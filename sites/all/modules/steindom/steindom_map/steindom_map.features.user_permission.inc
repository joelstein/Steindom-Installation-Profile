<?php
/**
 * @file
 * steindom_map.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function steindom_map_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fieldable steindom_map'.
  $permissions['create fieldable steindom_map'] = array(
    'name' => 'create fieldable steindom_map',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable steindom_map'.
  $permissions['delete fieldable steindom_map'] = array(
    'name' => 'delete fieldable steindom_map',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable steindom_map'.
  $permissions['edit fieldable steindom_map'] = array(
    'name' => 'edit fieldable steindom_map',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  return $permissions;
}
