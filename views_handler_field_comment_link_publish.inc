<?php
/**
 * Field handler to present a link to publish a comment.
 */
class views_handler_field_comment_link_publish extends views_handler_field_comment_link {
  function init(&$view, &$options) {
    parent::init($view, $options);
      $this->additional_fields['status'] = 'status';
  }  
  function render($values) {
    //needs permission to administer comments in general
    if (!user_access('administer comments') || $values->{$this->aliases['status']} == COMMENT_PUBLISHED) {
      return;
    }
    $text = !empty($this->options['text']) ? $this->options['text'] : t('publish');
    return l($text, "comment/publish/" . $values->{$this->aliases['cid']}, array('query' => drupal_get_destination()));
  }
}
