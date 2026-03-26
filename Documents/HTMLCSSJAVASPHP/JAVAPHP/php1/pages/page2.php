<h2> Παρουσιαση </h2>
<form action="index.php?selection=2" method="post">
    <fieldset>
        <legend> Στοιχεια χρηστη </legend>
        
        <label for="onoma">Onomateponimo:</label>
        <input type="text" name="onoma" id="onoma" autofocus >
        
        
        <label for="age">Ηλικία: </label>
        <input type="number" name="age" id="age" min="1" max="120" step="1" value="35" >
        <br>
        <button type="submit">Αποστολή</button>
        <button type="reset">Καθαρισμός</button>
        
           
        
        </fieldset>
</form>
<?php
if (isset($_POST["onoma"])) {   
    echo "<p>Ονομα: " . $_POST["onoma"] . "</p>";
    echo "<p>Ηλικια: " .  $_POST["age"] . "</p>";
   // παρε το τρεχον ετος
   // $y = date("Y");
    //παρε το τρεχον μηνα
   // $m = date("m");
   $courdate= getdate();
   $y=$courdate['year'];
   $m=$courdate['mon'];
    echo "<p> $m-$y </p>";
    //Μετέτρεψε τον δεκαδικό σε ακέραιο με την συνάρτηση intval ()
    $x=$y + $m/12.0;
    //echo "<p>$y</p>";
    
    //παρε την ηλικια που εστειλες
    $age = $_POST["age"];
    $etos = $x - $age;
    //
    $etos = intval($etos);
    echo "<p> Γιεννηθηκες το $etos </p>";
    
    if ($_POST["age"]>=18) {
        echo "<p> Εισαι Ενηλικος</p>";
    }
    else {
        echo "<p> Εισαι Aνηλικος</p>";
    }
}
?>
