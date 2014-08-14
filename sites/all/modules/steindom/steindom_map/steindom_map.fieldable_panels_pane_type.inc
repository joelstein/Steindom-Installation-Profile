<?php
/**
 * @file
 * steindom_map.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function steindom_map_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'steindom_map';
  $fieldable_panels_pane_type->title = 'Map';
  $fieldable_panels_pane_type->description = 'A Google map from a one-line address/location.';
  $export['steindom_map'] = $fieldable_panels_pane_type;

  return $export;
}
