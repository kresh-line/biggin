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
        
        $GLOBALS["RegisterErrorMsg"] = "";
        $GLOBALS["RegisterResultMsg"] = "";
        //Έλεγχος αν στάλθηκε η φόρμα
        if (isset($_POST["user"])) {
            $username = $_POST["user"];
            $pwd1 = $_POST["pswd"];
            $pwd2 = $_POST["pswd2"];
            $bd = $_POST["bd"];
            
            if (filter_var($username, FILTER_VALIDATE_EMAIL)==false || str_ends_with($username, "@gmail.com")==false)
                $msg = $msg . "Πρέπει να βάλετε email στο @gmail.com!<br>";

            if ($pwd1!=$pwd2)
                $msg = $msg . "Πρέπει ο κωδικός και η επιβεβαίωση να είναι ίδια!<br>"; 
            
            if (strlen($pwd1)<8 || strlen($pwd1)>30)
                $msg = $msg . "Πρέπει ο κωδικός να είναι μεταξύ 8 και 30 χαρακτήρων!<br>"; 
            
            $GLOBALS["RegisterErrorMsg"] = $msg;
            
            //Όλα τα δεδομένα είναι εντάξει
            if ($msg=="") {   
                $dbc = new DBConnector();
                $dbc->openConnection();
                $res = $dbc->registerUser($username, $pwd1, $bd);
                $dbc->closeConnection();
                
                //Αν η registerUser() επιστρέψει κενό, η εγγραφή έχει πετύχει
                if ($res=="") 
                    $GLOBALS["RegisterResultMsg"] = "<b>Η εγγραφή σας πέτυχε!</b>";
                else
                    $GLOBALS["RegisterResultMsg"] = "<b>$res</b>";
            }
        }
        
        require_once($GLOBALS['viewDir'] . '/register.php'); 
    }
    
    function test_noajax() {
        //Αν στάλθηκε η φόρμα υπολόγισε το αποτέλεσμα
        if (isset($_POST["num1"])) {
            $n1 = intval($_POST["num1"]);
            $n2 = intval($_POST["num2"]);
            $GLOBALS['addresult']  = "Αποτέλεσμα " . ($n1 + $n2);
        }
        else
           $GLOBALS['addresult'] = ""; 
        
        require_once($GLOBALS['viewDir'] . '/noajax.php');
    }
    
    function test_ajaxget() {
        require_once($GLOBALS['viewDir'] . '/ajaxget.php');
    }
    
    //Δεν στέλνω ολόκληρη τη σελίδα !!
    //Στέλνω μόνο το αποτέλεσμα
    function test_ajaxget_do() {
        //Αν στάλθηκε με AJAX με  GET
        if (isset($_GET["n1"])) {
            $n1 = intval($_GET["n1"]);
            $n2 = intval($_GET["n2"]);
            $n3 = intval($_GET["n3"]);
            echo "Αποτέλεσμα " . ($n1 + $n2 + $n3);
        }
        else
           echo ""; 
    }
    
    function test_ajaxpost() {
        require_once($GLOBALS['viewDir'] . '/ajaxpost.php');
    }    
    function test_ajaxpost_do() {
        //Αν στάλθηκε με AJAX με  POST
        if (isset($_POST["num1"])) {
            $n1 = intval($_POST["num1"]);
            $n2 = intval($_POST["num2"]);
            $n3 = intval($_POST["num3"]);
            echo "Αποτέλεσμα " . ($n1 + $n2 + $n3);
        }
        else
           echo ""; 
    }
    function test_ajaxpost_fetchapi() {
        require_once($GLOBALS['viewDir'] . '/ajaxpostfetchapi.php');
    }
    function Ask1() {
     require_once($GLOBALS['viewDir'] . '/ask1.php');
    }
    function login() {
        $_SESSION["user"]="client@gmail.com";

     require_once($GLOBALS['viewDir'] . '/login.php');
    }
    function apoth() {
        unset($_SESSION["user"]);
        require_once($GLOBALS['viewDir'] . '/apothi.php');
    }
    function manuals() {
        //unset($_SESSION["user"]);
        require_once($GLOBALS['viewDir'] . '/manual.php');
    } 
}