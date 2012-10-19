Drupal.behaviors.twittalicious = {
  attach: function(context) {
		if (Drupal.settings.twittalicious['reputation'] != undefined) {
		  Drupal.behaviors.twittalicious.charts = new Highcharts.Chart(Drupal.settings.twittalicious['reputation']);
    }
		if (Drupal.settings.twittalicious['following'] != undefined) {
		  Drupal.behaviors.twittalicious.charts = new Highcharts.Chart(Drupal.settings.twittalicious['following']);
    }
    if (Drupal.settings.twittalicious['conversation'] != undefined) {
		  Drupal.behaviors.twittalicious.charts = new Highcharts.Chart(Drupal.settings.twittalicious['conversation']);
      //alert(Drupal.behaviors.twittalicious.charts.title.textStr);
    }
		if (Drupal.settings.twittalicious['commitment'] != undefined) {
		  Drupal.behaviors.twittalicious.charts = new Highcharts.Chart(Drupal.settings.twittalicious['commitment']);
    }
		if (Drupal.settings.twittalicious['influence'] != undefined) {
		  Drupal.behaviors.twittalicious.charts = new Highcharts.Chart(Drupal.settings.twittalicious['influence']);
    }
		if (Drupal.settings.twittalicious['speed'] != undefined) {
		  Drupal.behaviors.twittalicious.charts = new Highcharts.Chart(Drupal.settings.twittalicious['speed']);
    }
  }
}

