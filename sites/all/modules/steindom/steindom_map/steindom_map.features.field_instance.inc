<?php
/**
 * @file
 * steindom_map.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function steindom_map_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'fieldable_panels_pane-steindom_map-field_steindom_map_location'
  $field_instances['fieldable_panels_pane-steindom_map-field_steindom_map_location'] = array(
    'bundle' => 'steindom_map',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'simple_gmap',
        'settings' => array(
          'iframe_height' => 300,
          'iframe_width' => '100%',
          'include_link' => 0,
          'include_map' => 1,
          'include_static_map' => 0,
          'include_text' => 0,
          'information_bubble' => 1,
          'langcode' => 'page',
          'link_text' => 'View larger map',
          'map_type' => 'm',
          'zoom_level' => 14,
        ),
        'type' => 'simple_gmap',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_steindom_map_location',
    'label' => 'Location',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Location');

  return $field_instances;
}
