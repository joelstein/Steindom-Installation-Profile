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
