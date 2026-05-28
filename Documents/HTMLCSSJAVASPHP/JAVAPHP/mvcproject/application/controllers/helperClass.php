<?php
class HelperClass {
        function printlongin() {
            if ($this->isLoggedIn() == null) {
                echo '<form id="loginform" action="" method="post">';
                echo '<fieldset>';
                echo '<label for="longinname">Όνομα:</label>';
                echo '<input type="text" name="longinname" id="longinname" required><br>';
                echo '<label for="pwd">Κωδικός:</label>';
                echo '<input type="password" name="pwd" id="pwd" required><br>';
                echo '<input type="submit" value="Σύνδεση">';
                echo '</fieldset>';
                echo '</form>';
                if (!empty($GLOBALS['loginError']))
                    echo '<span class="errormsg">' . $GLOBALS['loginError'] . '</span>';
            } else {
                echo "Καλωσήρθες " . $_SESSION['user'];
                echo '<form action="" method="post">';
                echo '<input type="hidden" name="logout">';
                echo '<input type="submit" value="Αποσύνδεση">';
                echo '</form>';
            }
        }

        // επιστρέφει το username αν έχει κάνει login, αλλιώς null
        function isLoggedIn() {
            if (isset($_SESSION['user'])) {
                return $_SESSION['user'];
            } else
                return null;
        }

        function logoutUser() {
            $_SESSION = [];
            session_destroy();
        }

        function loginUser($un, $pwd) {
            $db = new DBConnector();
            $db->openConnection();
            $pwdhash = $db->getUser($un);
            $db->closeConnection();
            if ($pwdhash == null)
                return "Δεν υπάρχει χρήστης με όνομα $un";
            else {
                if (password_verify($pwd, $pwdhash) == true) {
                    $_SESSION['user'] = $un;
                    return "";
                } else
                    return "Λάθος κωδικός!";
            }
        }
}
