<?php


	session_start();
	// $SESSION['user'] = 'test'; //gia test, na to afairesoume meta
	//$session einai to session pou xrisimopoioume gia na apothikeuoume ta dedomena tou xristi
	//apo to session pairnoume to username tou xristi an exei kanei login, alliws to username einai null
        //Φύλαξε το folder path της web εφαρμογής σου
	$site_path = realpath(dirname(__FILE__));
	
	require_once('application/router.php');

