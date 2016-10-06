<?php 
function getScript_resources()
{
	wp_enqueue_style( '_s-style', get_stylesheet_uri(), array(), time() );
}
	
add_action('wp_enqueue_scripts', 'getScript_resources');
	
//MENU
register_nav_menus(array(
	'primary' => __('Podstawowe Menu'),
));

show_admin_bar( false );

function remove_menus(){
  
#  remove_menu_page( 'index.php' );                  //Dashboard
  remove_menu_page( 'edit.php' );                   //Posts
  remove_menu_page( 'upload.php' );                 //Media
#  remove_menu_page( 'edit.php?post_type=page' );    //Pages
  remove_menu_page( 'edit-comments.php' );          //Comments
  remove_menu_page( 'link-manager.php' );          //Linki
#  remove_menu_page( 'themes.php' );                 //Appearance
  remove_menu_page( 'plugins.php' );                //Plugins
  remove_menu_page( 'users.php' );                  //Users
  remove_menu_page( 'tools.php' );                  //Tools
# remove_menu_page( 'options-general.php' );        //Settings
  
}

// REMOVE MENUS FROM WP_admin

add_action( 'admin_menu', 'remove_menus' );

add_action( 'admin_menu', 'adjust_the_wp_menu', 999 );
function adjust_the_wp_menu() {
  $page = remove_submenu_page( 'themes.php', 'theme-editor.php' );
  $page = remove_submenu_page( 'themes.php', 'themes.php' );
  $page = remove_submenu_page( 'themes.php', 'customize.php?return=%2Fwp-admin%2Fplugins.php' );
}

// POST TYPES

add_action( 'init', 'create_post_type' );

function create_post_type() {
  register_post_type( 'vimeovideos',
    array(
      'labels' => array(
        'name' => __( 'Vimeo Videos' ),
        'singular_name' => __( 'Vimeo video' )
      ),
      'public' => true,
	  'menu_icon' => 'dashicons-format-video',
	  'rewrite' => array( 'slug' => 'videos' ),
	  'supports' => array( 'title', 'editor', 'custom-fields' )


    )
  );
  
	register_post_type( 'photos',
		array(
		  'labels' => array(
			'name' => __( 'Photos' ),
			'singular_name' => __( 'Photos' )
		  ),
		  'public' => true,
		  'menu_icon' => 'dashicons-format-gallery',
		  'rewrite' => array( 'slug' => 'photos' ),
		  'supports' => array( 'title', 'editor', 'custom-fields' )
	
	
		)
	  );  
  
  
}



if(!function_exists("pokaz")) {
	function pokaz($tablica){
		echo "<pre>";
			print_r($tablica);
		echo "</pre>";	
	}
}

function ramka_vimeo($id){
	echo '<iframe src="https://player.vimeo.com/video/'.$id.'?color=ffffff"
	width="720" height="405" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>';
}

function ramka_yt($id){
	echo '<iframe width="720" height="400" src="https://www.youtube.com/embed/'.$id.'" frameborder="0" allowfullscreen></iframe>';
}


?>