<?php

function commentextra_views_data() {
  $data = array();
  
    // link to publish comment
  $data['comments']['publish_comment'] = array(
    'field' => array(
      'title' => t('Publish link'),
      'help' => t('Provide a simple link to publish the comment.'),
      'handler' => 'views_handler_field_comment_link_publish',
    ),
  );
    // link to unpublish comment
  $data['comments']['unpublish_comment'] = array(
    'field' => array(
      'title' => t('Unpublish link'),
      'help' => t('Provide a simple link to unpublish the comment.'),
      'handler' => 'views_handler_field_comment_link_unpublish',
    ),
  );
  return $data;
}

function commentextra_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'commentextra'),
    ),
    'handlers' => array(
      'views_handler_field_comment_link_publish' => array(
        'parent' => 'views_handler_field_comment_link',
      ),
      'views_handler_field_comment_link_unpublish' => array(
        'parent' => 'views_handler_field_comment_link',
      ),
    )
  );
}
