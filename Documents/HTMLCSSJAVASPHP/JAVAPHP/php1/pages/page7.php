<?php
if (isset($_SESSION["user"])) {





?>



<form action="index.php?selection=7" method="post">
    <fieldset>
        <legend> Στοιχεια Nεου Μαθητη </legend>
        <label for="am">Αριθμός Μητρώου: </label>
       <input type="number" name="am" id="am" min="1" max="9999" step="1" value="1"  required  >
        
        <label for="epon">Eπωνυμο:</label>
        <input type="text" name="epon" id="epon" autofocus required >
        
        <label for="onoma">Ονομα:</label>
        <input type="text" name="onoma" id="onoma" autofocus required >
        
        <br>
      
        <label for="bathm">Βαθμός:</label>
        <input type="number" name="bathm" id="bathm" min="0" max="10" step="1" value="5" required>
        <br>

        <button type="submit">Εισαγωγή μαθητή</button>
        <button type="reset">Καθαρισμός</button>
        
           
        
        </fieldset>
</form>
<?php
} 
else {
    echo "<p>Δεν έχεις δικαίωμα να εισάγεις μαθητή. Παρακαλώ κάνε login-in.</p>";
}
// αν έχει υποβληθεί η φόρμα, επεξεργαζόμαστε τα δεδομένα
if (isset($_POST["am"])) {   
    $am = $_POST["am"];
    $epon = $_POST["epon"];
    $on = $_POST["onoma"];
    $ex = $_POST["bathm"];

    $fp1 = fopen("data/mathites.txt", "a");
    fprintf($fp1, "%d\n %s\n %s\n %d\n", $am, $epon, $on, $ex);
    fclose($fp1);
    echo "<p>Ο μαθητής με ΑΜ $am Επώνυμο $epon και Όνομα $on και Βαθμός $ex προστέθηκε επιτυχώς.</p>";
}
?>