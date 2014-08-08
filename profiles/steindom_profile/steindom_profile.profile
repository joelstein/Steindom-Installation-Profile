<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function steindom_profile_form_install_configure_form_alter(&$form, $form_state) {
  // Move site information and admin account fieldsets up.
  $form['site_information']['#weight'] = -2;
  $form['admin_account']['#weight'] = -1;

  // Add user #2 fields.
  $form['user2'] = array(
    '#type' => 'fieldset',
    '#title' => 'User #2',
    '#tree' => TRUE,
    '#weight' => 0,
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

  // Set default country to US.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';

  // Add submit callback.
  $form['#submit'][] = 'steindom_profile_finished';
}

/**
 * Submit callback for site configuration form.
 */
function steindom_profile_finished(&$form, &$form_state) {
  // Save user #2.
  $user2 = array(
    'name' => $form_state['values']['user2']['name'],
    'pass' => $form_state['values']['user2']['pass'],
    'mail' => $form_state['values']['user2']['mail'],
    'init' => $form_state['values']['user2']['mail'],
    'timezone' => 'America/Chicago',
    'status' => 1,
    'access' => REQUEST_TIME,
    'roles' => array(3 => TRUE),
  );
  $account = user_save(null, $user2);

  // Login user #2.
  global $user;
  $user = user_load($account->uid);
  user_login_finalize();
}
