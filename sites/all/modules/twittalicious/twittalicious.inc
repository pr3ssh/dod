<?php

/**
 * @file twittalicious.inc
 */
/**
 * Campaign create function
 * @param $title - campaign node title
 */
function twittalicious_campaign_create($title) {

}

/**
 * Campaign delete function
 * @param $campaign_id - campaign node nid
 */
function twittalicious_campaign_delete($campaign_id) {

}

/**
 * Tweets search function
 * @param $search - search object with search criteria
 * @return $tweets - array of tweet objects that matched the search criteria
 */
function twittalicious_tweets_search($search) {

  return $tweets;
}

/**
 * User search function
 * @param $user - the user name to search
 */
function twittalicious_user_search($user) {

}

/**
 * Number of tweets function
 * @param $user - the user screen_name
 * @return number of tweets of the given user
 */
function twittalicious_statuses_count($user) {
  module_load_include('lib.php', 'twittalicious');

  $twittalicious = new Twittalicious();

  $statuses = $twittalicious->statuses_count($user);

  return $statuses;
}

/**
 * Number of retweets function
 * @param $user - the user screen_name
 * @return number of retweets received by the given user
 */
function twittalicious_retweets_count($user) {
  module_load_include('lib.php', 'twittalicious');

  $twittalicious = new Twittalicious();

  $retweets = $twittalicious->retweets_count($user);

  return $retweets;
}

/**
 * Number of followers function
 * @param $user - the user screen_name
 * @return number of followers of the given user
 */
function twittalicious_followers_count($user) {
  module_load_include('lib.php', 'twittalicious');

  $twittalicious = new Twittalicious();

  $followers = $twittalicious->followers_count($user);

  return $followers;
}

/**
 * Number of friends function
 * @param $user - the user screen_name
 * @return number of friends of the given user
 */
function twittalicious_friends_count($user) {
  module_load_include('lib.php', 'twittalicious');

  $twittalicious = new Twittalicious();

  $friends = $twittalicious->friends_count($user);

  return $friends;
}

/**
 * Number of lists function
 * @param $user - the user screen_name
 * @return number of lists created by the given user
 */
function twittalicious_lists_count($user) {
  module_load_include('lib.php', 'twittalicious');

  $twittalicious = new Twittalicious();

  $lists = $twittalicious->lists_count($user);

  return $lists;
}

/**
 * Number of lists where the user appears function
 * @param $user - the user screen_name
 * @return number of lists where the given user appears
 */
function twittalicious_listed_count($user) {
  module_load_include('lib.php', 'twittalicious');

  $twittalicious = new Twittalicious();

  $listed = $twittalicious->listed_count($user);

  return $listed;
}

/**
 * Number of tweets favourited by the given user
 * @param $user - the user screen_name
 * @return number of tweets favourited by the given user
 */
function twittalicious_favourites_count($user) {
  module_load_include('lib.php', 'twittalicious');

  $twittalicious = new Twittalicious();

  $favourites = $twittalicious->favourites_count($user);

  return $favourites;
}

/**
 * Channels list function
 * @returns $channels - array of channel names and info
 */
function twittalicious_channels_list() {
  $channels = array(
    'twitter' => array(
      'title' => 'Twitter',
    ),
  );

  return $channels;
}

/**
 * Creates a graph in JSON format
 * @param $name - the name of the graph you want to create
 * @returns $graph - the graph in JSON format
 */
function _twittalicious_graph_json($name) {
  module_load_include('charts.inc', 'twittalicious');

  $title = ucfirst($name) . ' Chart';
  $container = $name . '-container';

  $chart = _twittalicious_charts_demo($title, $container);

  $chart->chart->width = 320;
  $chart->chart->height = 410;
  $chart->exporting->enabled = false;

  return (object)array(
    'chart' => $chart,
  );
}

