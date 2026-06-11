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

require_once("application/HelperClass.php");
require_once($controllerDir . "/BasicController.php");
require_once($controllerDir . "/ProductController.php");

$PageSelection = "general";

//Ελέγχω εδώ πριν από όλες τις σελίδες μήπως ο χρήστης έχει στείλει
//τη φόρμα login για να τον κάνω login
$x = new HelperClass();
$LoginResult = $x->loginUser();
$x->logoutUser();


//Διαχειρίσου ξεχωριστά το AJAX Request με GET γιατί έχουμε
//URI που δεν είναι σταθερό αλλά αλλάζει με βάση τα ζεύγη
//ιδιοτήτων-τιμών μετά ? στο τέλος του σταθερού μέρους του URI 
if (substr($request,0,30) == '/mvcproject/test/ajax/get/res/') {
    $bc = new BasicController();
    $bc->test_ajaxget_do();
}
else {


switch ($request) {
    case $siteDir:
    case $siteDir . '/':
        
            $bc = new BasicController();
            $bc->home();
        break;

 case $siteDir . '/ask':
        case $siteDir . '/ask/':
		
                $bc = new BasicController();
                $bc->Ask1();
		break;


    case $siteDir . '/paroysiasi':
	case $siteDir . '/paroysiasi/':
            $bc = new BasicController();
            $bc->paroysiasi();
            break;
    case $siteDir . '/products/show':
	case $siteDir . '/products/show/':
            $PageSelection = "products";
            $sc = new ProductController();
            $sc->show();
            break;
            
    case $siteDir . '/products/add':
	case $siteDir . '/products/add/':
            $PageSelection = "products";
            $sc = new ProductController();
            $sc->add();
            break;
    
    case $siteDir . '/info':
	case $siteDir . '/info/':
            $bc = new BasicController();
            $bc->info();
            break;
        
    case $siteDir . '/test/noajax':
	case $siteDir . '/test/noajax/':
            $bc = new BasicController();
            $bc->test_noajax();
            break; 

    case $siteDir . '/test/ajax/get':
	case $siteDir . '/test/ajax/get/':
            $bc = new BasicController();
            $bc->test_ajaxget();
            break; 
        
    case $siteDir . '/test/ajax/post':
	case $siteDir . '/test/ajax/post/':
            $bc = new BasicController();
            $bc->test_ajaxpost();
            break; 


    case $siteDir . '/test/ajax/post/res':
	case $siteDir . '/test/ajax/post/res/':
            $bc = new BasicController();
            $bc->test_ajaxpost_do();
            break; 

case $siteDir . '/test/ajax/post/fetchapi':
	case $siteDir . '/test/ajax/post/fetchapi/':
            $bc = new BasicController();
            $bc->test_ajaxpost_fetchapi();
            break; 

    case $siteDir . '/register':
        case $siteDir . '/register/':
		$PageSelection = "register";
                $bc = new BasicController();
                $bc->register();
		break;

    default:
	$selection = "404";
        break;
}

}

