<?php 
    require_once("views/header.php"); 
    $etosmax = date("Y")-19;
    $etosval = date("Y") - 40;
?>
    <div id="content">
        <h1>Καλωσήρθατε στην σελίδα Εγγραφής</h1>
        <form class="productsformdiv" method="post">
            <fieldset><!-- comment -->
                <legend>Στοιχεία Εγγραφής</legend>    
                <label for="user">Δώστε Όνομα Χρήστη (e-mail στο @gmail.com):</label>
                <input type="email" id="user" name="user" required placeholder="Email στο @gmail.com" title="Email στο @gmail.com"><br>
                <label for="pswd">Δώστε Κωδικό:</label>
                <input type="password" id="pswd" name="pswd" required title="Ο Κωδικός σας να έχει από 8 μέχρι 30 χαρακτήρες με τουλάχιστον ένα αριθμό, ένα από τους @!#, ένα κεφαλαίο και ένα πεζό"><br>
                <label for="pswd2">Επιβεβαίωση Κωδικού:</label>
                <input type="password" id="pswd2" name="pswd2" required  title="Βάλτε τον ίδιο κωδικό για επιβεβαίωση"><br>
                <label for="bd">Έτος Γέννησης:</label>
                <input type="number" id="bd" name="bd" min="1950" <?php echo "max='$etosmax'"; ?>  <?php echo "value='$etosval'"; ?> required><br>
                <button type="submit">Αποστολή</button>
                <button type="reset">Καθαρισμός</button>
            </fieldset>
        </form>
        <span class="errormsg">
        <?php 
        echo $GLOBALS["RegisterErrorMsg"]; 
        ?>
        </span>
        <?php
            echo $GLOBALS["RegisterResultMsg"];
        ?>
        
    </div>
<?php 
    require_once("views/footer.php"); 
?>
