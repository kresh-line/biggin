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
        $msg = "";
        $GLOBALS["registererrorMsg"] = "";
        $GLOBALS["registerrezultMsg"] = "";
        //Ελέγχω αν έχω υποβληθεί η φόρμα
        if (isset($_POST["user"]) ) {
            $username = $_POST["user"];
            $pwd1 = $_POST["pswd"];
            $pwd2 = $_POST["pswd2"];
            $bd = $_POST["bd"];
            if (filter_var($username, FILTER_VALIDATE_EMAIL) !=true ||str_ends_with($username, "@gmail.com") == false) 
               $msg = $msg . "<h3>Το email πρέπει να είναι έγκυρο και να τελειώνει σε @gmail.com</h3>";
            
            if ($pwd1 != $pwd2) 
                $msg = $msg . "<h3>πρέπει οι κωδικοί πρόσβασης να ταιριάζουν</h3>";
            if (strlen($pwd1) < 8 || strlen($pwd1) > 30)
                $msg = $msg . "<h3>Ο κωδικός πρόσβασης πρέπει να είναι τουλάχιστον 8 χαρακτήρες και το πολύ 30</h3>";
            //Εδώ θα έπρεπε να κάνω έλεγχο για το αν τα
            $GLOBALS["registererrorMsg"] = $msg;
            if ($msg == "") {
                $dbc = new DBConnector();
                $dbc->openConnection();
                $res =  $dbc->registerUser($username, $pwd1, $bd);
                $dbc->closeConnection();

                
                //Εδώ θα έπρεπε να κάνω την εγγραφή του χρήστη στη βάση
                if ($res=="") 
                    $GLOBALS["registerrezultMsg"] = "<h3>Επιτυχής Εγγραφή</h3>";
                 else 
                    $GLOBALS["registerrezultMsg"] = "<br>$res<br>";
                
                //$GLOBALS["registerMsg"] = "<h3>Επιτυχής Εγγραφή</h3>";
            }
        }
        
        require_once($GLOBALS['viewDir'] . '/register.php'); 
    }

    function test_noalax() {
        require_once($GLOBALS['viewDir'] . '/noalax.php'); 
    }
    function test_alaxget() {
       require_once($GLOBALS['viewDir'] . '/alaxget.php'); 
    }
        //require_once($GLOBALS['viewDir'] . '/test_alax_get.php');}
    function test_alaxpost() {
         require_once($GLOBALS['viewDir'] . '/alaxpost.php');
    }
}