<?php
/**
 * @file
 * steindom_rich_text.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function steindom_rich_text_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fieldable steindom_rich_text'.
  $permissions['create fieldable steindom_rich_text'] = array(
    'name' => 'create fieldable steindom_rich_text',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable steindom_rich_text'.
  $permissions['delete fieldable steindom_rich_text'] = array(
    'name' => 'delete fieldable steindom_rich_text',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable steindom_rich_text'.
  $permissions['edit fieldable steindom_rich_text'] = array(
    'name' => 'edit fieldable steindom_rich_text',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  return $permissions;
}
