<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function steindom_form_install_configure_form_alter(&$form, $form_state) {
  // Set default country to US.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';

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
}
