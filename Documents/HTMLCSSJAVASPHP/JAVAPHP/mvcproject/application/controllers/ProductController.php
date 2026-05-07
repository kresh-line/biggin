<?php
require_once($GLOBALS['modelDir'] . "DBConnector.php");
class ProductController {
    private $x;

    function __construct() {

    }

    function show() {
        $dbc = new DBConnector();
        $dbc->openConnection();
        $dbc->closeConnection();
        require_once($GLOBALS ['viewDir'] . '/product/show.php');
    }

    function add() {
        require_once($GLOBALS ['viewDir'] . '/product/add.php');
    }

}





