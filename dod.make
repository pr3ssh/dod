; ----------------
; Generated makefile from http://drushmake.me
; Permanent URL: http://drushmake.me/file.php?token=7a45825f255f
; ----------------
;
; This is a working makefile - try it! Any line starting with a `;` is a comment.
  
; Core version
; ------------
; Each makefile should begin by declaring the core version of Drupal that all
; projects should be compatible with.
  
core = 7.x
  
; API version
; ------------
; Every makefile needs to declare its Drush Make API version. This version of
; drush make uses API version `2`.
  
api = 2
  
; Core project
; ------------
; In order for your makefile to generate a full Drupal site, you must include
; a core project. This is usually Drupal core, but you can also specify
; alternative core projects like Pressflow. Note that makefiles included with
; install profiles *should not* include a core project.
  
; Drupal 7.x. Requires the `core` property to be set to 7.x.
projects[drupal][version] = 7

  
  
; Modules
; --------
projects[admin][version] = 2.0-beta3
projects[admin][type] = "module"
projects[ctools][version] = 1.0
projects[ctools][type] = "module"
projects[date][version] = 2.3
projects[date][type] = "module"
projects[devel][version] = 1.2
projects[devel][type] = "module"
projects[features][version] = 1.0-rc1
projects[features][type] = "module"
projects[adaptivetheme][version] = 2.2
projects[adaptivetheme][type] = "module"
projects[entity][version] = 1.0-rc1
projects[entity][type] = "module"
projects[html5_tools][version] = 1.1
projects[html5_tools][type] = "module"
projects[imageapi][version] = 1.x-dev
projects[imageapi][type] = "module"
projects[jquery_ui][version] = 1.x-dev
projects[jquery_ui][type] = "module"
projects[libraries][version] = 1.0
projects[libraries][type] = "module"
projects[pathauto][version] = 1.0
projects[pathauto][type] = "module"
projects[rubik][version] = 4.0-beta8
projects[rubik][type] = "module"
projects[tao][version] = 3.0-beta4
projects[tao][type] = "module"
projects[views][version] = 3.3
projects[views][type] = "module"

projects[sparql_views][version] = 2.0-beta1
projects[sparql_views][type] = "module"
projects[rdfx][version] = 2.0-alpha4
projects[rdfx][type] = "module"
projects[sparql][version] = 2.0-alpha4
projects[sparql][type] = "module"

  

; Themes
; --------

  
  
; Libraries
; ---------
libraries[jquery][download][type] = "file"
libraries[jquery][download][url] = "https://ajax.googleapis.com/ajax/libs/jquery/1.6.0/jquery.min.js"
libraries[jqueryui][download][type] = "file"
libraries[jqueryui][download][url] = "https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.12/jquery-ui.min.js"



