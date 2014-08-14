<?php
/**
 * @file
 * steindom_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function steindom_image_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "fieldable_panels_panes" && $api == "fieldable_panels_pane_type") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function steindom_image_image_default_styles() {
  $styles = array();

  // Exported image style: steindom_image.
  $styles['steindom_image'] = array(
    'name' => 'steindom_image',
    'label' => 'Image',
    'effects' => array(),
  );

  return $styles;
}
