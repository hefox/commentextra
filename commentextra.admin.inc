<?php
/* unpublish, publish comments*/


function comment_unpublish($cid){
  $comment =  (array)_comment_load($cid) ;
  if ($comment['status'] == COMMENT_PUBLISHED) {
    $comment['status'] = COMMENT_NOT_PUBLISHED;
    comment_save($comment);
    if ($_GET['destination']) drupal_goto();
    return 'Comment unpublished';
  }
  if ($_GET['destination']) drupal_goto();
  return 'Comment already unpublished';
}

function comment_publish($cid){
  $comment =  (array)_comment_load($cid) ;
  if ($comment['status'] == COMMENT_NOT_PUBLISHED) {
    $comment['status'] = COMMENT_PUBLISHED;
    comment_save($comment);
    if ($_GET['destination']) drupal_goto();
    return 'Comment published';
  }
  if ($_GET['destination']) drupal_goto();
  return 'Comment already published';
}