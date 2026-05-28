<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Project/PHP/PHPProject.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>PHP ΣΕΛΙΔΑ</title>
        <link rel ="stylesheet" type="text/css" href="/mvcproject/css/format.css">
        <link rel ="stylesheet" type="text/css" href="/mvcproject/css/extra.css">
        <?php 
        if ($GLOBALS['pageSelection']=="products" || $GLOBALS['pageSelection']=="register") 
            echo "<link rel ='stylesheet' type='text/css' href='/mvcproject/css/products.css'>\n";
        
        ?>


    </head>
    <body>

<div id="main">
	<div id="header">
            <div id='logo'>EIKONA</div>
            <div id='centerheader'>
                
            </div>
            <div id='logdialog'>
        <?php
        
        $helper = new HelperClass();
        $helper->printlongin();
        ?>
            </div>
	</div>
	<div id="middle">
            
		<div id="menu">
		<ul class="verticalmenu">
		<li><a href=<?php echo $GLOBALS['siteDir'] . "/"; ?>>Αρχική Σελίδα</a></li>
		<li><a href=<?php echo $GLOBALS['siteDir'] . "/paroysiasi/"; ?>>Παρουσίαση</a></li>
		<li><a href=<?php echo $GLOBALS['siteDir'] . "/products/show/"; ?>>Προβολή Προϊόντων</a></li>
        <li><a href=<?php echo $GLOBALS['siteDir'] . "/products/add/"?>>Εισαγωγή Προϊόντος</a></li>
		<li><a href=<?php echo $GLOBALS['siteDir'] . "/info/"?>>Πληροφορίες</a></li>
                <li><a href="index.php?selection=5">Εικόνες</a></li>
                <li><a href="index.php?selection=10">Αγορές</a></li>
                <li><a href="index.php?selection=11">Ανέβασμα Αρχείου</a></li>
                <li><a href=<?php echo $GLOBALS['siteDir'] . "/products/register/"?>>Εγγραφή</a></li>
		</ul>
		</div>
            