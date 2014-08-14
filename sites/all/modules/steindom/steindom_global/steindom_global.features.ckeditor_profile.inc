<?php
/**
 * @file
 * steindom_global.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function steindom_global_ckeditor_profile_defaults() {
  $data = array(
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'skin' => 'moono',
        'ckeditor_path' => '//cdn.ckeditor.com/4.4.3/full-all',
        'ckeditor_local_path' => '',
        'ckeditor_plugins_path' => '%l/ckeditor-plugins',
        'ckeditor_plugins_local_path' => '',
        'ckfinder_path' => '%m/ckfinder',
        'ckfinder_local_path' => '',
        'ckeditor_aggregate' => 'f',
        'toolbar_wizard' => 't',
        'loadPlugins' => array(),
      ),
      'input_formats' => array(),
    ),
    'WYSIWYG' => array(
      'name' => 'WYSIWYG',
      'settings' => array(
        'ss' => 2,
        'toolbar' => '[
    [\'Source\',\'Format\',\'Bold\',\'Italic\',\'-\',\'NumberedList\',\'BulletedList\',\'Outdent\',\'Indent\',\'-\',\'JustifyLeft\',\'JustifyCenter\',\'JustifyRight\'],
    [\'Link\',\'Unlink\'],
    [\'Image\',\'IMCE\',\'Table\',\'MediaEmbed\',\'Youtube\',\'Blockquote\']
]',
        'expand' => 't',
        'default' => 't',
        'show_toggle' => 'f',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 't',
        'extraAllowedContent' => '',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'none',
        'css_path' => '',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 'f',
        'js_conf' => 'config.startupOutlineBlocks = true;
config.autoGrow_maxHeight = 550;',
        'loadPlugins' => array(
          'autogrow' => array(
            'name' => 'autogrow',
            'desc' => 'Auto Grow plugin. See <a href="http://ckeditor.com/addon/autogrow">addon page</a> for more details.',
            'path' => '//cdn.ckeditor.com/4.4.3/full-all/plugins/autogrow/',
            'buttons' => FALSE,
            'default' => 'f',
          ),
          'drupalbreaks' => array(
            'name' => 'drupalbreaks',
            'desc' => 'Plugin for inserting Drupal teaser and page breaks.',
            'path' => '%plugin_dir%drupalbreaks/',
            'buttons' => array(
              'DrupalBreak' => array(
                'label' => 'DrupalBreak',
                'icon' => 'images/drupalbreak.png',
              ),
            ),
            'default' => 't',
          ),
          'image2' => array(
            'name' => 'image2',
            'desc' => 'Plugin file: image2',
            'path' => '%plugin_dir_extra%image2/',
            'buttons' => FALSE,
            'default' => 'f',
          ),
          'imce' => array(
            'name' => 'imce',
            'desc' => 'Plugin for inserting files from IMCE without image dialog',
            'path' => '%plugin_dir%imce/',
            'buttons' => array(
              'IMCE' => array(
                'label' => 'IMCE',
                'icon' => 'images/icon.png',
              ),
            ),
            'default' => 'f',
          ),
          'mediaembed' => array(
            'name' => 'mediaembed',
            'desc' => 'Plugin for inserting Drupal embeded media',
            'path' => '%plugin_dir%mediaembed/',
            'buttons' => array(
              'MediaEmbed' => array(
                'label' => 'MediaEmbed',
                'icon' => 'images/icon.png',
              ),
            ),
            'default' => 'f',
          ),
          'tableresize' => array(
            'name' => 'tableresize',
            'desc' => 'Table Resize plugin. See <a href="http://ckeditor.com/addon/tableresize">addon page</a> for more details.',
            'path' => '//cdn.ckeditor.com/4.4.3/full-all/plugins/tableresize/',
            'buttons' => FALSE,
            'default' => 't',
          ),
          'youtube' => array(
            'name' => 'youtube',
            'desc' => 'Plugin file: youtube',
            'path' => '%plugin_dir_extra%youtube/',
            'buttons' => array(
              'Youtube' => array(
                'label' => 'Youtube',
                'icon' => 'images/icon.png',
              ),
            ),
            'default' => 'f',
          ),
        ),
      ),
      'input_formats' => array(
        'wysiwyg' => 'WYSIWYG',
      ),
    ),
  );
  return $data;
}
