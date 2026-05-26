<?php 
    require_once("views/header.php"); 
    $etosmax = date("Y") - 19;
    $etosval = date("Y") - 40;
?>
    <div id="content">
        <h1>Καλωσήρθατε στην σελίδα Εγγραφής</h1>

        <form class="productsformdiv" method="post">

            <fieldset>
                <legend> Στοιχεία Εγγραφής</legend>
                <label for="user">Όνομα Χρήστη: (email)</label>
                <input type="email" id="user" name="user" required placeholder="Email sto @gmail.com" title="Please enter a valid email address"><br>

                <label for="pswd">Κωδικός Πρόσβασης:</label>
                <input type="password" id="pswd" name="pswd" required  title="Ο κωδικός πρόσβασης πρέπει να περιλαμβάνει τουλάχιστον 8 χαρακτήρες και να περιλαμβάνει τουλάχιστον έναν αριθμό"><br>

                 <label for="pswd2">Επιβεβαίωση Κωδικού:</label>
                <input type="password" id="pswd2" name="pswd2" required  title="Ο κωδικός πρόσβασης πρέπει να είναι ίδιος με τον πρώτο"><br>

                 <label for="bd">Ετος Γέννησης:</label>
                <input type="number" id="bd" name="bd" min="1900" <?php echo "max='$etosmax'";?> <?php echo "min='$etosval'";?> required><br>
                <button type="submit">Αποστολή</button>
                <button type="reset">Καθαρισμός</button>
             <!-- <input type="submit" value="Εγγραφή"> -->
            </fieldset>
        </form>
        <span class="errormsg">
        <?PHP 
            echo $GLOBALS["registererrorMsg"];
        ?>
        </span>
        <span class="resultmsg">
        <?PHP 
            echo $GLOBALS["registerrezultMsg"];
        ?>
        </span>
    </div>
<?php 
    require_once("views/footer.php"); 
?>	


    