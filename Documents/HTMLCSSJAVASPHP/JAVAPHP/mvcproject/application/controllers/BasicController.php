<?php

class BasicController {
    private $x;
    
    function __construct() {
        
    }
    
    function home() {

        require_once($GLOBALS ['viewDir'] . '/home.php'); 
    }
    
    function paroysiasi() {
        require_once($GLOBALS ['viewDir'] . '/paroysiasi.php'); 
    }
    
    function info() {
        require_once($GLOBALS ['viewDir'] . '/info.php'); 
    }
}


// CLASS DBConnector {
//     function __construct() {
        
//     }
// }