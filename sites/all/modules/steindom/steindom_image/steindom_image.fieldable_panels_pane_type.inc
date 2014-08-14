<?php
/**
 * @file
 * steindom_image.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function steindom_image_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'steindom_image';
  $fieldable_panels_pane_type->title = 'Image';
  $fieldable_panels_pane_type->description = 'An image with an optional link.';
  $export['steindom_image'] = $fieldable_panels_pane_type;

  return $export;
}
