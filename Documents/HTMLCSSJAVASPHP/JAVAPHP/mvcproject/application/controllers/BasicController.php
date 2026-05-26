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
    function register() {
        if (isset($_POST["user"]) ) {
            //Εδώ θα έπρεπε να κάνω έλεγχο για το αν τα πεδία είναι σωστά συμπληρωμένα
            //και μετά να κάνω την εγγραφή στη βάση δεδομένων
            //Αλλά για την ώρα απλά θα εμφανίζω τα στοιχεία που έστειλε ο χρήστης
            $GLOBALS["registerMsg"] = "<h3>Εγγραφή με τα εξής στοιχεία:</h3>";
        }
        else {
            $GLOBALS["registerMsg"] = "<h3>Παρακαλώ συμπληρώστε τα στοιχεία εγγραφής</h3>";
        }
        require_once($GLOBALS['viewDir'] . '/register.php'); 
    }
}