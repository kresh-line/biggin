<?php

class BasicController {
    private $x;
    
    function __construct() {
        
    }
    
    function home() {
        require_once('views/home.php'); 
    }
    
    function paroysiasi() {
        require_once('views/paroysiasi.php'); 
    }
    
    function info() {
        require_once('views/info.php'); 
    }
}