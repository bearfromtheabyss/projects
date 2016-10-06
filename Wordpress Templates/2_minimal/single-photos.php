<?php

	get_header();

    if ( have_posts() ) : while ( have_posts() ) : the_post();

?>



<?php
	$gallery=get_post_meta( get_the_ID() , 'gallery');

	if(isset($gallery)){
		echo '	<section class="content" id="left">';
			echo do_shortcode($gallery[0]);
		echo '</section>';
		echo  '<section class="content" id="right">';
	}else{
		echo '<section class="content" id="left">';	
	}

?>    
		<?php the_content(); ?>
</section>



</section>
<?php /*
<section class="content" id="right">
	<?php the_content(); ?>
</section>
*/ ?>
        
<?php

	endwhile; endif;
 	
	get_footer(); 
    
?>

