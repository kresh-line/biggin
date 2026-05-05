<?php
        //Φύλαξε το folder path της web εφαρμογής σου
	$site_path = realpath(dirname(__FILE__));
		//chdir($site_path);

	require_once('application/router.php');

?>