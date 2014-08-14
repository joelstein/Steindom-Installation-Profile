<?php
/**
 * @file
 * steindom_rich_text.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function steindom_rich_text_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'fieldable_panels_pane-steindom_rich_text-field_steindom_rich_text_content'
  $field_instances['fieldable_panels_pane-steindom_rich_text-field_steindom_rich_text_content'] = array(
    'bundle' => 'steindom_rich_text',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_steindom_rich_text_content',
    'label' => 'Content',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');

  return $field_instances;
}
