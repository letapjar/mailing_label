<?php
// $Id: mailing_label.views.inc,v 1.2.2.1 2009/07/26 00:19:30 acouch Exp $

/**
 * Implementation of hook_views_plugins
 */
function mailing_label_views_plugins() {
  $views_path = drupal_get_path('module', 'views');
  return array(
    'display' => array(
      // Parents are not really displays, just needed so the files can
      // be included.
      'parent' => array(
        'no ui' => TRUE,
        'handler' => 'views_plugin_display',
        'path' => "$views_path/plugins",
        'parent' => '',
      ),
     'attachment' => array(
       'no ui' => TRUE,
       'handler' => 'views_plugin_display_attachment',
       'path' => "$views_path/plugins",
       'parent' => 'parent',
     ),
     'mailing' => array(
       'title' => t('Mailing Labels'),
       'help' => t('Make PDF mailing labels.'),
       'handler' => 'mailing_label_plugin_display_attachment',
       'parent' => 'attachment',
       'theme' => 'views_view',
       'admin' => t('Mailing Labels'),
       'help topic' => 'mailing-labels',
     ), 
        
  ), 
  );
}

function mailing_label_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'mailing_label'),
     ),
    'handlers' => array(
      'mailing_label_handler_field' => array(
        'parent' => 'content_handler_field_multiple',
      ),
    ),
  );
}
 
