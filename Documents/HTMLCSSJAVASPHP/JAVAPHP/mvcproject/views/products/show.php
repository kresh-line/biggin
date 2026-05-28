<?php 
    require_once("views/header.php"); 
?>
    <div id="content">
        <h1>Προβολή Προϊόντων</h1>
        <?php 
        if ($GLOBALS['username']!=null) {
            echo $GLOBALS['results'];

        }
        else {
            echo "<p>Δεν έχεις κάνει σύνδεση. Παρακαλώ συνδέσου για να δεις τα προϊόντα.</p>";
        }
       // echo $GLOBALS['case'];
        ?>
        <script src="/mvcproject/js/jscode.js"></script>
    </div>
<?php 
    require_once("views/footer.php"); 
?>	

