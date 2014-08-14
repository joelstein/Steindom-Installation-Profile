<?php
/**
 * @file
 * steindom_rich_text.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function steindom_rich_text_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'steindom_rich_text';
  $fieldable_panels_pane_type->title = 'Rich-text';
  $fieldable_panels_pane_type->description = 'Rich text content.';
  $export['steindom_rich_text'] = $fieldable_panels_pane_type;

  return $export;
}
