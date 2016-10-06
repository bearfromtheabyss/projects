<?php

	get_header();

    if ( have_posts() ) : while ( have_posts() ) : the_post();

?>

<section class="content" id="left">

<?php

// SPRAWDZENIE CZY JEST YT CZY VIMEO

$vimeo=FALSE;
$yt=FALSE;
$vimeo_m=FALSE;
$yt_m=FALSE;

$meta=get_post_meta( get_the_ID() );

if (array_key_exists('vimeo_id', $meta)) {
 	$vimeo_id=get_post_meta( get_the_ID(), 'vimeo_id', true ); 
	if(isset($vimeo_id)){
		$vimeo=TRUE;
	}
}

if (array_key_exists('yt_id', $meta)) {
	$yt_id=get_post_meta( get_the_ID(), 'yt_id', true );
	if(isset($yt_id)){
		$yt=TRUE;
	}
}

if($vimeo){

		if (strpos($vimeo_id,';') !== false) {
			$vimeo_m=TRUE;
			$vimeo_ids=explode(";",$vimeo_id);
		}	
		
		if($vimeo_m){
			for ($i = 0; $i < count($vimeo_ids); $i ++) {
				ramka_vimeo($vimeo_ids[$i]);
			}
		}else{
			ramka_vimeo($vimeo_id);
		}
		
}

if($yt){
	
		if (strpos($yt_id,';') !== false) {
			$yt_m=TRUE;
			$yt_ids=explode(";",$yt_id);
		}	
		
		if($yt_m){
			for ($i = 0; $i < count($yt_ids); $i ++) {
				ramka_yt($yt_ids[$i]);
			}
		}else{
			ramka_yt($yt_id);
		}		

}

?>    
</section>

<section class="content" id="right">
	<?php the_content(); ?>
</section>

        
<?php

	endwhile; endif;
 	
	get_footer(); 
    
?>

