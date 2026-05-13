<?php

class BasicController {
    public $x;
    
    
    function __construct() {
        
    }
    //Παίρνει παράμετρο το path που είναι τα views
    function home() {
        require_once($GLOBALS['viewDir'] . '/home.php'); 
    }
    
    function paroysiasi() {
        require_once($GLOBALS['viewDir'] . '/paroysiasi.php'); 
    }
    
    function info() {
        require_once($GLOBALS['viewDir'] . '/info.php'); 
    }
}