<?php
/**
 * @file twittalicious.lib.php
 * Classes to implement the full Twittalicious API
 */

/**
 * Class Twittalicious
 * Extends the Twitter Class with useful features
 */
module_load_include('lib.php', 'twitter');

class Twittalicious extends Twitter{

  /**
   * Returns users info for a giving id or screen name
   *
   * @param $id
   *   user id or screen name
   * @param $params
   *   array of parameters for the api call
   * @param $use_auth
   *   sets if the call is authenticated or not
   * @return
   *   user info in json format
   * @see https://dev.twitter.com/docs/api/1/get/users/show
   */
  public function users_show($id, $params = array(), $use_auth = FALSE) {
    if (is_numeric($id)) {
      $params['user_id'] = $id;
    }
    else {
      $params['screen_name'] = $id;
    }

    return $this->call('1/users/show', $params, 'GET', $use_auth);
  }

  /**
   * Returns the number of tweets of the user
   *
   * @param $id
   *   user id or screen name
   * @return
   *   number of tweets of the user
   */
  public function statuses_count($id) {
    $result = $this->users_show($id);

    return $result['statuses_count'];
  }

  /**
   * Returns the number of retweets of the user
   *
   * @param $id
   *   user id or screen name
   * @return
   *   number of retweets of the user
   * @TODO implement the retweets count function
   */
  public function retweets_count($id) {
    $result = $this->users_show($id);

    return 0;
  }

  /**
   * Returns the number of followers of the user
   *
   * @param $id
   *   user id or screen name
   * @return
   *   number of followers of the user
   */
  public function followers_count($id) {
    $result = $this->users_show($id);

    return $result['followers_count'];
  }

  /**
   * Returns the number of friends of the user
   *
   * @param $id
   *   user id or screen name
   * @return
   *   number of friends of the user
   */
  public function friends_count($id) {
    $result = $this->users_show($id);

    return $result['friends_count'];
  }

  /**
   * Returns the number of lists created by a user
   *
   * @param $id
   *   user id or screen name
   * @param $params
   *   array of parameters for the api call
   * @param $use_auth
   *   sets if the call is authenticated or not
   * @return
   *   number of lists created by the given user
   * @see https://dev.twitter.com/docs/api/1/get/lists
   */
  public function lists_count($id, $params = array(), $use_auth = FALSE) {
    if (is_numeric($id)) {
      $params['user_id'] = $id;
    }
    else {
      $params['screen_name'] = $id;
    }

    $lists = $this->call('1/lists', $params, 'GET', $use_auth);
    
    return sizeof($lists['lists']);
  }

  /**
   * Returns the number of lists where the user appears
   *
   * @param $id
   *   user id or screen name
   * @return
   *   number of lists where the user appears
   */
  public function listed_count($id) {
    $result = $this->users_show($id);

    return $result['listed_count'];
  }

  /**
   * Returns the number of tweets favourited by the user
   *
   * @param $id
   *   user id or screen name
   * @return
   *   number of tweets favourited by the user
   */
  public function favourites_count($id) {
    $result = $this->users_show($id);

    return $result['favourites_count'];
  }

}

