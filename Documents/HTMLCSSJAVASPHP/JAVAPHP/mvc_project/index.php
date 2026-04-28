<?php
/**
 * Front Controller - Pika hyrëse e aplikacionit
 *
 * Çdo kërkesë kalon këtu falë .htaccess
 * Merr URL-në dhe e dërgon tek Router për dispatch
 */

// Ngarko Router
require_once 'core/Router.php';

// Merr URL-në nga query string
$url = isset($_GET['url']) ? $_GET['url'] : 'home';

// Pastro URL-në (hiq karaktere të panevojshme)
$url = rtrim($url, '/');
$url = filter_var($url, FILTER_SANITIZE_URL);

// Krijo Router dhe bëj dispatch
$router = new Router();
$router->dispatch($url);

// </div> end header 
	// <div id="middle">
           
		/*<div id="menu">
		<ul class="verticalmenu">
		<li><a href="index.php?selection=1&nikos=5">Αρχική Σελίδα</a></li>
		<li><a href="index.php?selection=2">Παρουσίαση</a></li>
		<li><a href="index.php?selection=3">Προβολη Μαθητη</a></li>
      <li><a href="index.php?selection=7">Εισαγωγη Μαθητη</a></li>
		<li><a href="index.php?selection=4">Πληροφορίες</a></li>
      <li><a href="index.php?selection=5">Εικονες</a></li>
      <li><a href="index.php?selection=10">Αγορες</a></li>
      <li><a href="index.php?selection=10">Ανεβασμα Αρχείων</a></li>
		</ul>
		</div>
	    
		
	
	<div id="content">
           
         <?php
           
            if (isset($_GET["selection"])) {       
            if ($_GET["selection"] == 1) {
               include("pages/page1.php");
            }
           else if ($_GET["selection"] == 2) {        
            include("pages/page2.php");      
         }
           else if ($_GET["selection"] == 3) {
              include("pages/page3.php");
         }
           else if ($_GET["selection"] == 4) {         
             include("pages/page4.php");
          }
          
          else if ($_GET["selection"] == 5) {         
             include("pages/page5.php");
          }
           else if ($_GET["selection"] == 6) {         
           include("pages/page6.php"); 
           
           }
           else if ($_GET["selection"] == 7) {         
           include("pages/page7.php"); 
         
           }
         else if ($_GET["selection"] == 8) {
            if (isset($_SESSION["user"])) {
               echo "<h3>Καλώς ήρθες χρήστη!</h3>";
            }
             include("pages/page1.php");
            }

            else if ($_GET["selection"] == 9) {         
           echo "<h3>Έχεις αποσυνδεθεί!</h3>";
            }
            else if ($_GET["selection"] == 10) {
               include ("pages/page10.php");
            }
            else if ($_GET["selection"] == 11) {
               include ("pages/page11.php");
            }
             else {
            echo "Δεν βρέθηκε επιλογή";
          }
            }
            ?>

        </div>
        </div>
       </div>
            
           
            
           


        <div id="footer">
            
 </div>
        <script src="js/main.js"></script>
  </body>
 </html> */