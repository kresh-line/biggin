<?php

// Ο Δρομολογητής μας θα ελέγχει το URL και ανάλογα θα δρομολογεί στον κατάλληλο
//controller και από εκεί στην κατάλληλη view ή κατευθείαν στην κατάλληλη view.

//Αποθήκευσε το URI (το τμήμα του URL μετά το host) σε μία μεταβλητή.
//Ο πίνακας $_SERVER έχει στοιχεία που φορτώνει ο web server και αφορούν το αίτημα 
//όπως headers, paths, και script locations
$request = $_SERVER['REQUEST_URI'];

//Αποθήκευσε το φάκελο που είναι το site γιατί θα βρίσκεται μπροστά στο URI 
//και πρέπει να το βάζω για να εξετάσω τι ακολουθεί μετά ώστε να δω που θα 
//δρομολογήσω
$siteDir = '/mvcproject';

//Αποθήκευσε το φάκελο που είναι οι controllers
$controllerDir = 'application/controllers';

//Αποθήκευσε το φάκελο που είναι οι controllers
$modelDir = 'application/Models';


//Αποθήκευσε το φάκελο που είναι οι views
//Η viewDir είναι global άρα θα αναφέρομαι σε αυτήν μέσα σε
//functions γράφοντας $GLOBALS['viewDir'] 
$viewDir = 'views';

require_once($controllerDir . "/BasicController.php");
require_once($controllerDir . "/ProductController.php");

$pageSelection ="general";

switch ($request) {
    case $siteDir:
    case $siteDir . '/':
        
            $bc = new BasicController();
            $bc->home();
        break;

    case $siteDir . '/paroysiasi':
	case $siteDir . '/paroysiasi/':
            $bc = new BasicController();
            $bc->paroysiasi();
            break;
    case $siteDir . '/products/show':
	case $siteDir . '/products/show/':
            $pageSelection = "products";
            $sc = new ProductController();
            $sc->show();
            break;
            
    case $siteDir . '/products/add':
	case $siteDir . '/products/add/':
            $pageSelection = "products";
            $sc = new ProductController();
            $sc->add();
            break;
    
    case $siteDir . '/info':
	case $siteDir . '/info/':
            $bc = new BasicController();
            $bc->info();
            break;
        
    case $siteDir . '/products/register':
        case $siteDir . '/products/register/':
		    $pageSelection = "register";
            $bc = new BasicController();
            $bc->register();
		break;

    default:
	$selection = "404";
        break;
}

//Εμφάνισε τη σελίδα  
//require_once('views/layout.php');  
