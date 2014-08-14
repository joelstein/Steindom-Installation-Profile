<?php
/**
 * @file
 * steindom_image.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function steindom_image_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'fieldable_panels_pane-steindom_image-field_steindom_image_image'
  $field_instances['fieldable_panels_pane-steindom_image-field_steindom_image_image'] = array(
    'bundle' => 'steindom_image',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_link_formatter',
        'settings' => array(
          'image_link' => 'field_steindom_image_link',
          'image_style' => 'steindom_image',
        ),
        'type' => 'image_link_formatter',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_steindom_image_image',
    'label' => 'Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'fpp-image',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'fieldable_panels_pane-steindom_image-field_steindom_image_link'
  $field_instances['fieldable_panels_pane-steindom_image-field_steindom_image_link'] = array(
    'bundle' => 'steindom_image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_steindom_image_link',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => -3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Image');
  t('Link');

  return $field_instances;
}
