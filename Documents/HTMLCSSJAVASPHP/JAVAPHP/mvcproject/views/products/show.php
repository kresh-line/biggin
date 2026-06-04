<?php 
    require_once("views/header.php"); 
?>
    <div id="content">
        <h1>Προβολή Προϊόντων</h1>
        <?php 
        //echo $GLOBALS['case'];
        //Αν έχει κάνει login
        if ($GLOBALS['username']!=null)
            echo $GLOBALS['results']; 
        else //Αν δεν έχει κάνει login
            echo "<p>Πρέπει να κάνετε σύνδεση για να χρησιμοποιήσετε αυτή τη σελίδα!</p>";
        ?>
        <script src="/mvcproject/js/jscode.js"></script>
    </div>
<?php 
    require_once("views/footer.php"); 
?>	

