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
$siteDir = '/phpprojects/mvc';

//Αποθήκευσε το φάκελο που είναι οι controllers
$controllerDir = '/controllers/';

//Αποθήκευσε το φάκελο που είναι οι views
$viewDir = '/views/';

switch ($request) {
    case $siteDir:
    case $siteDir . '/':
		$selection = "HOME";
        //require __DIR__ . $viewDir . 'home.php';
        break;

    case $siteDir . '/users':
	case $siteDir . '/users/':
		$selection = "USERS";
        //require __DIR__ . $viewDir . 'users.php';
		break;

    case $siteDir . '/contact':
        case $siteDir . '/contact/':
		$selection = "CONTACT";
        //require __DIR__ . $viewDir . 'contact.php';
		break;

    default:
		$selection = "404";
        //http_response_code(404);
        //require __DIR__ . $viewDir . '404.php';
        break;
}

//Εμφάνισε τη σελίδα  
require_once('views/layout.php');  
?>