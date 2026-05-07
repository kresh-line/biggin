<?php
require_once('$modelDir' . "/DBConnector.php");
class StudentController {
    private $x;
    
    function __construct() {
        
    }
    
    function show() {
        $dbc = new DBConnector();
        $dbc->openConnection();
        $dbc->closeConnection();
        require_once($GLOBALS ['viewDir'] . '/students/show.php'); 
    }
    
    function add() {
        require_once($GLOBALS ['viewDir'] . '/students/add.php'); 
    }
    
}





