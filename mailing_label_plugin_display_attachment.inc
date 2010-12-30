<?php
// $Id: mailing_label_plugin_display_attachment.inc,v 1.3.2.3 2009/10/25 00:53:53 acouch Exp $

/**
 * The plugin that handles date navigation attachments.
 * 
 * Creates a special attachment for this purpose only. 
 */
class mailing_label_plugin_display_attachment extends views_plugin_display_attachment {
  
  function defaultable_sections($section = NULL) {
    if (in_array($section, array('row_options', 'row_plugin', 'items_per_page'))) {
      return FALSE;
    }
    return parent::defaultable_sections($section);
  }

  function options(&$display) {
    parent::options($display);
    $display->display_options['items_per_page'] = 0;
    $display->display_options['row_plugin'] = '';
    $display->display_options['defaults']['style_options'] = FALSE;
    $display->display_options['defaults']['items_per_page'] = FALSE;
    $display->display_options['defaults']['row_plugin'] = FALSE;
    $display->display_options['defaults']['row_options'] = FALSE;
  } 

  function render() {
    $current_display = $this->view->current_display;
    $fields = $this->view->display[$current_display]->handler->handlers['field'];
    $view=$this->view;
    $i=0;
    foreach ($view->result as $result) {
      foreach ($result as $rid => $output) {
        foreach ($view->field as $id => $field) {
          $results[$i][$id] = check_plain(strip_tags(($view->field[$id]->theme($result))));
        }
      }
    $i++;
    }
   
    return mailing_label_pdf_form($results,$current_display);
  }


}

