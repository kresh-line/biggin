<?php
class HelperClass {
        function printlongin() {
            ?>
        <form id="loginform" action=<?php echo $GLOBALS['siteDir'] . "/login"; ?> method="post">
         <fieldset>

            <label for="longinname">Όνομα:</label>
            <input type="text" name="longinname" id="longinname"><br>
            <label for="pwd">Κωδικός:</label>
            <input type="password" name="pwd" id="pwd"><br>
        
        <input type="submit" value="Σύνδεση">
         </fieldset>
        </form>
        
<?php

        }
        // μεθοδος που ελέγχει αν ο χρήστης έχει κάνει login, επιστρέφει το username του χρήστη αν έχει κάνει login, αλλιώς επιστρέφει null
        function isLoggedIn() {
            if (isset($_SESSION['user'])) {
                return $_SESSION['user'];
            } else 
                return null;
            
        }
}

