<?php

	get_header();
?>

<section class="content">

	<?php
        if ( have_posts() ) : while ( have_posts() ) : the_post();
    ?>
        
        <article class="post">
                <?php the_content(); ?>
        </article>
        
    <?php endwhile; endif; ?>
    
</section>        	
            
<?php get_footer(); ?>