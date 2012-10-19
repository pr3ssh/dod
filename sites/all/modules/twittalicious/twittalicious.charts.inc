<?php

/**
 * @file twittalicious.chart
 *   Classes to implement the full twittalicious charts API
 */

/**
 * Class Chart
 * Implements the highcharts config object
 */
class Chart{
  // Protected variables

  // Public variables
  public $title;
  public $subtitle;
  public $chart;
  public $credits;
  public $series;

  // Constructor for the Chart class
  public function __construct($options = NULL) {
    if (!empty($options)) {
      $this->set_config($options);
    }
  }

  // Sets the global chart config
  public function set_config($config) {
    $this->config = $config;
  }

  /**
   * Sets the general chart options:
   * @param $container
   *   the div id where the chart will be rendered.
   * @param $type
   *   the chart type (line, spline, area, areaspline, column, bar, pie and
   *   scatter). Defaults to "line".
   * @param $zoom
   *   chart zoom type (x, y or xy). Defaults to "".
   */
  public function set_chart_options($container, $type = 'line', $zoom = NULL) {
    $this->chart->renderTo = $container;
    $this->chart->type = $type;
    $this->chart->marginBottom = 120;
    $this->chart->width = 440;
    $this->chart->height = 350;

    if (isset($zoom)) {
      $this->chart->zoomType = $zoom;
    }
  }

  // Sets the chart title
  public function set_title($title) {
    $this->title->text = $title;
  }

  // Sets the chart subtitle
  public function set_subtitle($subtitle) {
    $this->subtitle->text = $subtitle;
  }

  // Sets the xAxis options
  public function set_xaxis($title = '') {
    $this->xAxis->title->text = $title;
    $this->xAxis->title->align = 'center';
    $this->xAxis->categories = array('a month ago', 'three weeks ago', 'two weeks ago', 'a week ago', 'today');
    $this->xAxis->labels->rotation = 315;
    $this->xAxis->labels->align = 'right';
  }

  // Sets the yAxis options
  public function set_yaxis($text = '') {
    $this->yAxis->title->text = $text;
    $this->yAxis->min = 0;
  }

  // Sets the chart legend options
  public function set_legend() {
    $this->legend->enabled = TRUE;
    $this->legend->layout = 'horizontal';
    $this->legend->backgroundColor = '#FFFFFF';
    $this->legend->floating = TRUE;
    $this->legend->y = 5;
    $this->legend->shadow = TRUE;
  }

  // Sets the chart tooltip options
  // @TODO: This feature does not work so I have to do the work in the js file
  public function set_tooltip($options) {
    $this->tooltip->formatter = NULL;
  }

  // Sets the highcharts credits options
  public function set_credits($title = 'twittalicious.com', $url = 'http://twittalicious.com', $enabled = FALSE) {
    $this->credits->title = $title;
    $this->credits->href = $url;
    $this->credits->enabled = $enabled;
  }

  // Plot options
  public function plot_options() {
    $this->plotOptions->column->pointPadding = 0.2;
    $this->plotOptions->column->borderWidth = 0;
  }

  public function set_serie($name, $data) {
    $serie = new stdClass();
    $serie->name = $name;
    $serie->data = $data;
    $this->series[] = $serie;
  }

  /**
   * Returns random chart data for a given number of items
   * @return $series
   *   array of data objects
   * @param $items
   *   items to display on the chart
   * @param $values
   *   number of values for each item
   */
  public function set_random_serie($name, $values) {
    $serie = new stdClass();
    $serie->name = $name;
    $serie->data = $this->get_random_values($values);
    $this->series[] = $serie;
  }

  /**
   * Returns random data for the charts
   * @return $data
   *   array of random numbers
   * @param $values
   *   array of random numbers size
   */
  private function get_random_values($values) {
    $data = array();

    for ($i = 1; $i <= $values; $i++) {
      $data[] = rand(100, 1000);
    }

    return $data;
  }
}

/**
 * Renders a custom chart using the Highcharts library and config
 * @param
 *   $params - chart config params
 * @return
 *   $output - the container where the chart will be rendered
 */
function _twittalicious_charts_show($type = NULL) {
  module_load_include('module', 'libraries', 'libraries');
  $path = libraries_get_path('highcharts');

  drupal_add_js($path . '/js/highcharts.js');
  drupal_add_js($path . '/js/modules/exporting.js');
  drupal_add_js(drupal_get_path('module', 'twittalicious') . '/js/charts.js');
  drupal_add_css(drupal_get_path('module', 'twittalicious') . '/css/charts.css');

  if ($type == 'demo') {
    $reputation = _twittalicious_charts_demo('Reputation Indicators', 'reputation-chart');
    $following = _twittalicious_charts_demo('Following Analysis', 'following-chart');
    $conversation = _twittalicious_charts_demo('Conversation Indicators', 'conversation-chart');
    $commitment = _twittalicious_charts_demo('Commitment Analysis', 'commitment-chart');
    $influence = _twittalicious_charts_demo('Influence Indicators', 'influence-chart');
    $speed = _twittalicious_charts_demo('Speed Analysis', 'speed-chart');
  }
  else {
    $series = array();
    $series[] = array(
      'name' => '@rteijeiro',
      'data' => array(10, 20, 30, 40, 50),
    );
    $series[] = array(
      'name' => '@davidjguru',
      'data' => array(2, 45, 67, 89, 90),
    );
    $reputation = _twittalicious_charts_create('Reputation Indicators', 'reputation-chart', $series);
    $following = _twittalicious_charts_create('Following Analysis', 'following-chart', $series);
    $conversation = _twittalicious_charts_create('Conversation Indicators', 'conversation-chart', $series);
    $commitment = _twittalicious_charts_create('Commitment Analysis', 'commitment-chart', $series);
    $influence = _twittalicious_charts_create('Influence Indicators', 'influence-chart', $series);
    $speed = _twittalicious_charts_create('Speed Analysis', 'speed-chart', $series);
  }

  drupal_add_js(array("twittalicious" => array('reputation' => $reputation)), "setting");
  drupal_add_js(array("twittalicious" => array('following' => $following)), "setting");
  drupal_add_js(array("twittalicious" => array('conversation' => $conversation)), "setting");
  drupal_add_js(array("twittalicious" => array('commitment' => $commitment)), "setting");
  drupal_add_js(array("twittalicious" => array('influence' => $influence)), "setting");
  drupal_add_js(array("twittalicious" => array('speed' => $speed)), "setting");

  return TRUE;
}

function _twittalicious_charts_demo($title, $container) {
  $chart = new Chart();
  $chart->set_title($title);
  $chart->set_subtitle('Twittalicious');
  $chart->set_chart_options($container);
  $chart->set_xaxis();
  $chart->set_yaxis();
  $chart->set_legend();
  $chart->set_credits();
  $chart->set_random_serie('Followers', 5);
  $chart->set_random_serie('Follows', 5);
  $chart->set_random_serie('Lists', 5);

  return $chart;
}

function _twittalicious_charts_create($title, $container, $series) {
  $chart = new Chart();
  $chart->set_title($title);
  $chart->set_subtitle('Twittalicious');
  $chart->set_chart_options($container);
  $chart->set_xaxis();
  $chart->set_yaxis();
  $chart->set_legend();
  $chart->set_credits();

  foreach ($series as $serie) {
    $chart->set_serie($serie['name'], $serie['data']);
  }

  return $chart;
}
