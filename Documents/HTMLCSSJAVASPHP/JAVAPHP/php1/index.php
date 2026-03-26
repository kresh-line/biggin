<?php

session_start();


?>

<!DOCTYPE html>

<html>
    <head>
        <meta charset="UTF-8">
        <title>PHP ΣΕΛΙΔΑ</title>
        <link rel ="stylesheet" type="text/css" href="css/format.css">
        <link rel="stylesheet" type="text/css" href="css/extra.css">
    </head>
    <body>
<div id="main">
	<div id="header">
      <div id="logo">
         ΕΙΚΟΝΑ
        </div>
        <div id="center">
        <h1> PHP ΣΕΛΙΔΑ </h1> 
        <?php echo session_id(); ?>
        </div>
     <div id="logdialog">

   <?php

   // Διαχείριση σύνδεσης και αποσύνδεσης χρήστη
      if (isset($_GET["selection"]) && $_GET["selection"] == 8 && isset($_POST["user"])) {
      if (isset($_POST["user"]))
      $_SESSION["user"]= $_POST["user"];

      }
   // Ελεγχος αν ο χρήστης είναι συνδεδεμένος ή όχι
    if (isset($_GET["selection"]) && $_GET["selection"] == 9) {
      if (isset($_SESSION["user"])) 
          unset($_SESSION["user"]);
         if (isset($_SESSION["numshow"])) 
          unset($_SESSION["numshow"]);
         if (isset($_SESSION["images"])) 
          unset($_SESSION["images"]);
             
      }
         if (isset($_SESSION["user"])) {
          echo "<p>Καλωσηρθες " . $_SESSION["user"];
          echo " <a href='index.php?selection=9'>Αποσύνδεση</a></p>";
         }  else
            {
?>
            
   
   <form id="loginform" action="index.php?selection=8" method="post">
    <fieldset>
        <legend> Συνδέση </legend>
        
        <label for="user">Χρήστης:</label>
        <input type="text" name="user" id="user" autofocus required >
        
        <label for="pswd">Κωδικός:</label>
        <input type="password" name="pswd" id="pswd" autofocus required >
        
        <br>
   

        <button type="submit">Σύνδεση</button>
        <button type="reset">Καθαρισμός</button>
        
           
        
        </fieldset>
</form>

<?php
            }
            ?>
        </div>
	</div><!-- end header -->
	<div id="middle">
           
		<div id="menu">
		<ul class="verticalmenu">
		<li><a href="index.php?selection=1&nikos=5">Αρχική Σελίδα</a></li>
		<li><a href="index.php?selection=2">Παρουσίαση</a></li>
		<li><a href="index.php?selection=3">Προβολη Μαθητη</a></li>
      <li><a href="index.php?selection=7">Εισαγωγη Μαθητη</a></li>
		<li><a href="index.php?selection=4">Πληροφορίες</a></li>
      <li><a href="index.php?selection=5">Εικονες</a></li>
      <li><a href="index.php?selection=10">Αγορες</a></li>
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
 </html> 

 