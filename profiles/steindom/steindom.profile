<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function steindom_form_install_configure_form_alter(&$form, $form_state) {
  // Set default country to US.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';

  // Add theme name field.
  $form['site_information']['theme_name'] = array(
    '#type' => 'textfield',
    '#title' => 'Theme short name',
    '#required' => TRUE,
  );

  // Add user #2 fields.
  $form['user2'] = array(
    '#type' => 'fieldset',
    '#title' => 'User #2',
    '#tree' => TRUE,
  );
  $form['user2']['name'] = array(
    '#type' => 'textfield',
    '#title' => 'Username',
    '#required' => TRUE,
    '#default_value' => 'Joel Stein',
  );
  $form['user2']['mail'] = array(
    '#type' => 'textfield',
    '#title' => 'Email',
    '#required' => TRUE,
    '#default_value' => 'joel@steindom.com',
  );
  $form['user2']['pass'] = array(
    '#type' => 'password',
    '#title' => 'Password',
    '#required' => TRUE,
  );

  // Add Pathologic local paths field, and set defaults for my usual Prod,
  // Staging, and Dev URL conventions.
  global $base_url;
  $prod = preg_replace('/dev$/', 'com', $base_url);
  $staging = preg_replace('/^http:\/\//', 'http://staging.', $prod);
  $form['server_settings']['pathologic_local_paths'] = array(
    '#type' => 'textarea',
    '#title' => 'Pathologic local paths',
    '#default_value' => "$prod/\n$staging/\n$base_url/\n/",
    '#weight' => -1,
  );

  // Adjust weight of other fieldsets.
  $form['server_settings']['#weight'] = 1;
  $form['update_notifications']['#weight'] = 2;

  // Add submit callback.
  $form['#submit'][] = 'steindom_finished';
}

/**
 * Submit callback for site configuration form.
 */
function steindom_finished(&$form, &$form_state) {
  // Set contact form email address to site email.
  db_query("UPDATE {webform_emails} SET email = :email WHERE nid = 1", array(
    ':email' => $form_state['values']['site_mail'],
  ));

  // Save user #2.
  $user2 = array(
    'name' => $form_state['values']['user2']['name'],
    'pass' => $form_state['values']['user2']['pass'],
    'mail' => $form_state['values']['user2']['mail'],
    'status' => 1,
    'access' => REQUEST_TIME,
    'roles' => array(3 => TRUE),
  );
  $account = user_save(null, $user2);

  // Login user #2.
  global $user;
  $user = user_load($account->uid);
  user_login_finalize();

  // Save Pathologic local paths in text formats.
  foreach (array('full_html', 'full_html_no_wysiwyg', 'filtered_html') as $format_id) {
    if ($format = filter_format_load($format_id)) {
      $format->filters = array();
      foreach (filter_list_format($format_id) as $filter_name => $filter) {
        $format->filters[$filter_name] = (array) $filter;
      }
      $format->filters['pathologic']['settings']['local_paths'] = $form_state['values']['pathologic_local_paths'];
      filter_format_save($format);
    }
  }

  // Make sure themes directory exists.
  chmod('sites/default', 0775);
  $destination = 'sites/default/themes';
  file_prepare_directory($destination, FILE_CREATE_DIRECTORY);
  chmod('sites/default', 0555);

  // Clone Omega starter theme.
  $theme = $form_state['values']['theme_name'];
  $source = 'sites/all/themes/omega/starterkits/omega-html5';
  $destination = "sites/default/themes/$theme";
  steindom_copy_recursive($source, $destination);

  // Rename .info file.
  $source = "sites/default/themes/$theme/starterkit_omega_html5.info";
  $destination = "sites/default/themes/$theme/$theme.info";
  file_unmanaged_move($source, $destination);

  // Update .info file.
  $info = drupal_parse_info_file($destination);
  $info['name'] = $form_state['values']['site_name'];
  $info['description'] = 'An Omega sub-theme.';
  unset($info['hidden'], $info['starterkit'], $info['version'], $info['project'], $info['datestamp']);
  $data = steindom_build_info_file($info);
  file_unmanaged_save_data($data, $destination, FILE_EXISTS_REPLACE);

  // Rename CSS files.
  foreach (array('', '-narrow', '-normal', '-wide') as $part) {
    $source = "sites/default/themes/$theme/css/YOURTHEME-alpha-default$part.css";
    $destination = "sites/default/themes/$theme/css/$theme-alpha-default$part.css";
    file_unmanaged_move($source, $destination);
  }

  // Set new theme as default theme.
  system_rebuild_theme_data();
  theme_enable(array($theme));
  variable_set('theme_default', $theme);
  system_rebuild_theme_data();
  menu_rebuild();
}

/**
 * Recursively copies a folder.
 * A copy of omega_tools_copy_recursive().
 */
function steindom_copy_recursive($source, $destination) {
  if (is_dir($source)) {
    if (!file_prepare_directory($destination, FILE_CREATE_DIRECTORY)) {
      return FALSE;
    }
    $directory = dir($source);
    while (FALSE !== ($read = $directory->read())) {
      if ($read != '.' && $read != '..' ) {      
        if (!steindom_copy_recursive($source . '/' . $read, $destination . '/' . $read)) {
          return FALSE;
        }
      }
    }
    $directory->close();
  } 
  else {
    file_unmanaged_copy($source, $destination);
  }
  return TRUE;
}

/**
 * Converts an array to PHP ini format.
 * A copy of omega_tools_build_info_file().
 */
function steindom_build_info_file($array, $prefix = FALSE) {
  $info = '';
  foreach ($array as $key => $value) {
    if (is_array($value)) {
      $info .= steindom_build_info_file($value, (!$prefix ? $key : "{$prefix}[{$key}]"));
    }
    else {
      $info .= $prefix ? ("{$prefix}[" . $key .']') : $key;
      $info .= " = '" . str_replace("'", "\'", $value) . "'\n";
    }
  }
  return $info;
}
