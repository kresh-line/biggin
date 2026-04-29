<?php

class StudentController {
    private $x;
    
    function __construct() {
        
    }
    
    function show() {
        require_once('views/students/show.php'); 
    }
    
    function add() {
        require_once('views/students/add.php'); 
    }
    
}





