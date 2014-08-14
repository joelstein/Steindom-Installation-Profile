<?php
/**
 * @file
 * steindom_image.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function steindom_image_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fieldable steindom_image'.
  $permissions['create fieldable steindom_image'] = array(
    'name' => 'create fieldable steindom_image',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable steindom_image'.
  $permissions['delete fieldable steindom_image'] = array(
    'name' => 'delete fieldable steindom_image',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable steindom_image'.
  $permissions['edit fieldable steindom_image'] = array(
    'name' => 'edit fieldable steindom_image',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  return $permissions;
}
