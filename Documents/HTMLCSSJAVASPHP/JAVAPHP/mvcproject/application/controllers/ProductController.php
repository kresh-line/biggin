<?php

require_once($modelDir . "/DBConnector.php");

class ProductController {
    private $x;
    
    function __construct() {
        
    }
    
    /* Η μέθοδος θα κληθεί σε 3 περιπτώσεις:
     * 1) Ο χρήστης πάτησε προβολή ή έγραψε το url
     * 2) Ο χρήστης πάτησε "Ενημέρωση" σε ένα προϊόν
     * 3) Ο χρήστης πάτησε "Διαγραφή" σε ένα προϊόν
     */
    function show() {
        // prostateyoume tin selida mas gia na min exei prosvasi xoris login
        $hp = new HelperClass();
        $GLOBALS['username'] = $hp->isLoggedIn();

        if ($GLOBALS['username'] !=null) {
           
        

        //Ελέγχω ποια περίπτωση έχω
        //Ελέγχω αν έχω ενημέρωση προϊόντος
        if (isset($_POST['pid'])) {
            $dbc = new DBConnector();
            $dbc->openConnection();
            $num = $dbc->updateProduct($_POST['pid'], $_POST['pname'], $_POST['pprice'], $_POST['pcat']);
            $dbc->closeConnection();
            if ($num==1)
                $GLOBALS['case'] = "<h3>Ενημερώθηκε το προϊόν " . $_POST['pid'] . "</h3>";
            else
                $GLOBALS['case'] = "<h3>Δεν ενημερώθηκε το προϊόν " . $_POST['pid'] . "</h3>";
        }
        else //Ελέγχω αν έχω διαγραφή προϊόντος
            if (isset($_POST['delpid'])) {
                $dbc = new DBConnector();
                $dbc->openConnection();
                $num = $dbc->deleteProduct($_POST['delpid']);
                $dbc->closeConnection();
                if ($num==1)
                    $GLOBALS['case'] = "<h3>Διαγράφτηκε το προϊόν " . $_POST['delpid'] . "</h3>";
                else
                    $GLOBALS['case'] = "<h3>Δεν διαγράφτηκε το προϊόν " . $_POST['delpid'] . "</h3>";
            }
            else
                $GLOBALS['case'] = "<h3>Απλή προβολή</h3>";
        
        $dbc = new DBConnector();
        $dbc->openConnection();
        $GLOBALS['results'] = $dbc->getProductsAsForms();
        $dbc->closeConnection();
        
        require_once($GLOBALS['viewDir'] . '/products/show.php'); 
    }
    }
    function add() {
        $hp = new HelperClass();
        $GLOBALS['username'] = $hp->isLoggedIn();

        if ($GLOBALS['username'] != null) {
            if (isset($_POST["pname"]) && trim($_POST["pname"]) !== "" && floatval($_POST["pprice"]) > 0) {
                $dbc = new DBConnector();
                $dbc->openConnection();
                $success = $dbc->insertProduct(trim($_POST["pname"]), $_POST["pprice"], $_POST["pcat"]);
                $dbc->closeConnection();
                $GLOBALS["insertProductResult"] = $success ? true : false;
            }

            $dbc = new DBConnector();
            $dbc->openConnection();
            $GLOBALS['categories'] = $dbc->getCategories();
            $dbc->closeConnection();
        }

        require_once($GLOBALS['viewDir'] . '/products/add.php');
    }
    
}





