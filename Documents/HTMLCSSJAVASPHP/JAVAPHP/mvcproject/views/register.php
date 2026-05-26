<?php 
    require_once("views/header.php"); 
    $etosmax = date("Y") - 19;
    $etosval = date("Y") - 40;
?>
    <div id="content">
        <h1>Καλωσήρθατε στην σελίδα Εγγραφής</h1>

        <form method="post">
            <fieldset>
                <legend> Στοιχεία Εγγραφής</legend>
                <label for="user">Όνομα Χρήστη: (email)</label>
                <input type="email" id="user" name="user" required><br>

                <label for="pswd">Κωδικός Πρόσβασης:</label>
                <input type="password" id="pswd" name="pswd" required><br>

                 <label for="pswd2">Επιβεβαίωση Κωδικού:</label>
                <input type="password" id="pswd2" name="pswd2" required><br>

                 <label for="bd">Ετος Γέννησης:</label>
                <input type="number" id="bd" name="bd" min="1900" <?php echo "max='$etosmax'";?> <?php echo "min='$etosval'";?> required><br>
                <button type="submit">Αποστολή</button>
                <button type="reset">Καθαρισμός</button>
             <!-- <input type="submit" value="Εγγραφή"> -->
            </fieldset>
        </form>
    </div>
<?php 
    require_once("views/footer.php"); 
?>	

    