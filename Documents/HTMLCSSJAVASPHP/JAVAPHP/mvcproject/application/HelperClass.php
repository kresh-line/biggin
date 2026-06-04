<?php

class HelperClass {
   
    function printLoginForm() {
        if ($this->isLoggedIn()==null) {
    ?>    
    <form id="loginform" action="" method="post">
    <fieldset>
    <label for="loginname">Όνομα:</label>
    <input type="text" name="loginname" id="loginname" required><br>
    <label for="pwd">Κωδικός:</label>
    <input type="password" name="pwd" id="pwd" required><br>
    <input type="submit" value="Σύνδεση">
    </fieldset>
    </form>
    <?php
    echo "<span class='errormsg'>" . $GLOBALS['LoginResult'] . "</span>";
    
        } 
        else {
            echo "Καλωσήρθες " . $_SESSION['user'];
            ?>
            <form action="" method="post">
            <input type="hidden" name="logout"><br>
            <input type="submit" value="Αποσύνδεση">
            </form>
            <?php
        }
    }
    
    //Μέθοδος που ελέγχει αν υπάρχει στον πίνακα $_SESSION
    ////το στοιχείο 'user' το οποίο δημιουργώ όταν ο χρήστης
    ////κάνει logging και σβήνω όταν κάνει loggout.
    // Στον πίνακα $_SESSION αποθηκεύουμε όλες οι πληροφορίες που θέλω
    //να διατηρώ για το session. 
    function isLoggedIn() {
        if (isset($_SESSION['user'])) {
            return $_SESSION['user'];
        }
        else
            return null;
    }
    
    
    /*
     * Επιστρέφει κενό sring αν όλα πάνε καλά αλλιώς επιστρέφει
     * το μήνυμα λάθους
     */
    function loginUser() {
        //Αν έχει σταλεί η login form
        if (isset($_POST['loginname'])) {
            $un = $_POST['loginname'];
            $pwd = $_POST['pwd'];
        
            $dbc = new DBConnector();
            $dbc->openConnection();
            $pwdhash = $dbc->getUserPwd($un);
            $dbc->closeConnection();

            //Αν δεν βρέθηκε ο χρήστης επέστρεψε  
            if ($pwdhash==null) 
                return "Δεν υπάρχει αυτός ο χρήστης!";
            else {
                if (password_verify($pwd,$pwdhash)==true) {
                    //Κάνω Login τον χρήστη
                    $_SESSION['user']=$un;
                    return "";
                }
                else 
                   return "Λάθος κωδικός!"; 
            }
        }
        else //Αν δεν έχει κάνει προσπάθεια Login επέστρεψε πάλι κενό
            return "";
    }
    
    
    function logoutUser() {
        //Αν πατήθηκε το κουμπί logout τότε στάλθηκε με post το
        //κρυφό πεδίο logout
        if (isset($_POST['logout'])) {
            unset($_SESSION['user']);
        }
    }

}
