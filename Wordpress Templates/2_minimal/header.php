<html>
<head>
    <meta charset = "utf-8">
    <meta name = "viewport" content="width=device-width">
    <title><?php bloginfo('name'); ?></title>
    <META name="Description" content="<?php bloginfo('description'); ?>">
    
    <script src="http://code.jquery.com/jquery-latest.min.js" type="text/javascript"></script>
    <?php wp_head();?>
</head>
<body <?php body_class(); ?>>
	
    <header>
   		<div class="logo">
        	<a href="index.php">
        		<img src="<?php bloginfo('template_url'); ?>/img/logo_kruszka.png" />
        	</a>        
        </div>
        <nav>
            <?php wp_nav_menu( array( 'theme_location' => 'primary', 'menu_class' => 'nav-menu' ) ); ?>
        </nav>
    </header>