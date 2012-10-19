<?php

/**
 * @file twittalicious.pages.inc
 */

/**
 * Returns the twittalicious demo dashboard
 */
function twittalicious_demo() {
  $output = drupal_render(drupal_get_form('twittalicious_dashboard_form', 'demo'));

  return $output;
}

/**
 * Returns the twittalicious dashboard
 * @TODO: Create tpl and theme function for the dashboard output
 */
function twittalicious_dashboard() {
  $output = drupal_render(drupal_get_form('twittalicious_dashboard_form', 'dashboard'));

  return $output;
}

/**
 * Returns the dashboard form
 * @return $form - the dashboard form
 */
function twittalicious_dashboard_form($form, &$form_state, $type) {

  $form_state['storage']['type'] = $type;

  $form['channel'] = array(
    '#type' => 'select',
    '#title' => t('Channel'),
    '#default_value' => 'twitter',
    '#options' => array('twitter' => t('Twitter')),
  );

  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#default_value' => 'user',
    '#options' => array(
      'user' => t('User'),
      'comparative' => t('Comparative'),
      'hashtag' => t('Hashtag'),
    ),
  );

  $form['search'] = array(
    '#type' => 'textfield',
    '#title' => t('Search'),
    '#default_value' => 'twittalicious',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Go!'),
  );

  if (!isset($form_state['storage']['chart'])) {
    $form['demo-text'] = array(
      '#markup' => '<div class="demo-text"><p>Esta Demo simplemente pretende mostrar el funcionamiento de Twittalicious.</p><p>Los datos que devuelve la aplicación son ficticios por lo que no deben ser tenidos en cuenta.</p>Las gráficas representadas sí están basadas en las métricas que Twittalicious utilizará en un futuro.</p><p>Muy pronto estará disponible la versión Beta de Twittalicious a través de invitaciones. Permanece atento en <a href="http://twittalicious.com" target="_blank">twittalicious.com</a> ya que estamos trabajando duro y en pocos días estará online</p><strong>El equipo de Twittalicious</strong></div>',
    );
  }

  if (isset($form_state['storage']['chart'])) {
    $form['reputation'] = array(
      '#type' => 'fieldset',
      '#title' => t('Reputation Metrics'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['reputation']['charts'] = array(
      '#markup' => '<div id="reputation-chart">Reputation Chart</div><div id="following-chart">Following Chart</div>',
    );
  }

  if (isset($form_state['storage']['chart'])) {
    $form['conversation'] = array(
      '#type' => 'fieldset',
      '#title' => t('Conversation Metrics'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['conversation']['charts'] = array(
      '#markup' => '<div id="conversation-chart">Conversation Chart</div><div id="commitment-chart">Commitment Chart</div>',
    );
  }

  if (isset($form_state['storage']['chart'])) {
    $form['influence'] = array(
      '#type' => 'fieldset',
      '#title' => t('Influence Metrics'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['influence']['charts'] = array(
      '#markup' => '<div id="influence-chart">Influence Chart</div><div id="speed-chart">Speed Chart</div>',
    );
  }

  return $form;
}

/**
 * Dashboard form validation function
 */
function twittalicious_dashboard_form_validate($form, &$form_state) {
}

/**
 * Dashboard form submit function
 * @TODO: Review the function that returns the charts
 */
function twittalicious_dashboard_form_submit($form, &$form_state) {
  module_load_include('inc', 'twittalicious');
  module_load_include('charts.inc', 'twittalicious');

  switch ($form_state['values']['type']) {
    case 'user':
      $form_state['storage']['chart'] = _twittalicious_charts_show($form_state['storage']['type']);
      $form_state['rebuild'] = TRUE;
      break;
    case 'comparative':
      drupal_set_message(t('Sorry, the Twittalicious comparative search will be available soon. Stay tuned!'), 'warning');
      break;
    case 'hashtag':
      drupal_set_message(t('Sorry, the Twittalicious hashtag search will be available soon. Stay tuned!'), 'warning');
      break;
  }

}

/**
 * Returns the campaign create form
 */
function twittalicious_campaign_create_form($form, &$form_state) {

  $form = array();

  return $form;
}

/**
 * Campaign create form validation function
 */
function twittalicious_campaign_create_form_validate($form, &$form_state) {

}

/**
 * Campaign create form submit function
 */
function twittalicious_campaign_create_form_submit($form, &$form_state) {

}

