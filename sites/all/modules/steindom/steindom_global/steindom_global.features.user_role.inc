<?php
/**
 * @file
 * steindom_global.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function steindom_global_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
