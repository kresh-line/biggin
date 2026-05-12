<?php
require_once($GLOBALS['modelDir'] . "DBConnector.php");
class ProductController {
    private $x;

    function __construct() {

    }
 // η μεθοδος show είναι αυτή που θα εμφανίζει τα προϊόντα και θα καλείται από τον router όταν ο χρήστης ζητήσει να δει τα προϊόντα
 // 2 βήματα: 1. να πάρει τα προϊόντα από τη βάση δεδομένων και 2. να φορτώσει τη σελίδα που θα εμφανίζει τα προϊόντα
    function show() {
        if (isset($_POST['pid']) ) {
            $GLOBALS['case'] = "<h3>Ενημέρωση προϊόντος με κωδικό: " . $_POST['pid'] . "</h3>";
        }
           else if (isset($_POST['delpit'])) {
            $GLOBALS['case'] = "<h3>Διαγραφή προϊόντος με κωδικό: " . $_POST['delpit'] . "</h3>";
           }
           else {
            $GLOBALS['case'] = "<h3>Εμφάνιση προϊόντων</h3>";}
            
        
        $dbc = new DBConnector();
        $dbc->openConnection();
        $GLOBALS ['results'] =  $dbc ->getProductsAsFroms();//getProducts();
        $dbc->closeConnection();

        require_once($GLOBALS ['viewDir'] . '/product/show.php');
    }

    function add() {
        require_once($GLOBALS ['viewDir'] . '/product/add.php');
    }

}





