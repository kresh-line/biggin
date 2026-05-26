<?php

class DBConnector {
    private $host; //Το host που τρέχει ο MySQL Server
    private $user; //Το όνομα χρήστη με το οποίο συνδέομαι
    private $pswd; //Ο κωδικός χρήστη με το οποίο συνδέομαι
    private $db; //Το όνομα της ΒΔ
    private $conn; //Εδώ αποθηκεύεται η σύνδεση που έχω κάνει
    
    //Ο δημιουργός της κλάσης ο οποίος συνήθως αρχικοποιεί
    //τις ιδιότητες της κλάσης
    function __construct() {
        $this->host = "localhost";
        $this->user = "root";
        $this->pswd = "";
        $this->db = "productsdb";
        $this->conn = null;
    }
    
    function openConnection() {
        $this->conn = mysqli_connect($this->host, $this->user, $this->pswd, $this->db);
    }
    
    
    function closeConnection() {
        //Κλείσε τη σύνδεση
        if ($this->conn != null) {
            mysqli_close($this->conn);  
        }
    }
    
    function getProducts() {
        $sql = "select products.id, products.name, price, categories.name ";
        $sql = $sql . " from products inner join categories on products.catid=categories.id";
        //Εκτέλεση ερωτήματος
        $res = mysqli_query($this->conn, $sql);
        //Δες πόσες εγγραφές επιλέχτηκαν
        $num = mysqli_num_rows($res);
        
        $str = "<table class='results'>\n";
        $str = $str . "<tr><th>Κωδικός</th><th>Όνομα</th><th>Τιμή</th><th>Κατηγορία</th></tr>";
        for ($i=0; $i<$num; ++$i) {
            $r = mysqli_fetch_array($res);
            $str = $str . "<tr><td>$r[0]</td><td>$r[1]</td><td>$r[2]</td><td>$r[3]</td></tr>\n";
        }
        $str = $str . "</table>\n";
        return $str;  
    }
   
    function getProductsAsForms() {
        //Πάρε τις κατηγορίες σαν πίνακα που κάθε στοιχείο του 
        //είναι πίνακας δύο στοιχείων (id και name)
        $categ = $this->getCategories();
        
        $sql = "select * from products";
        //Εκτέλεση ερωτήματος
        $res = mysqli_query($this->conn, $sql);
        //Δες πόσες εγγραφές επιλέχτηκαν
        $num = mysqli_num_rows($res);
        
        $str = "";
        for ($i=0; $i<$num; ++$i) {
            $r = mysqli_fetch_array($res);
            $str = $str . "<div class='productsformdiv'>\n";
            $str = $str . "<form id='updateForm$r[0]' onsubmit='return validateUpdateForm($r[0])' method='post'><fieldset>\n";
            $str = $str . "<label for='pid$r[0]'>Κωδικός</label>\n";
            $str = $str . "<input type='text' id='pid$r[0]' name='pid' value='$r[0]' readonly>\n";
            $str = $str . "<label for='pname$r[0]'>Όνομα</label>\n";
            $str = $str . "<input type='text' id='pname$r[0]' name='pname' value='$r[1]'>\n";
            $str = $str . "<label for='pprice$r[0]'>Τιμή</label>\n";
            $str = $str . "<input type='number' id='pprice$r[0]' name='pprice' value='$r[2]'>\n";
            
            $str = $str . "<label for='pcat$r[0]'>Κατηγορία</label>\n";
            $str = $str . "<select id='pcat$r[0]' name='pcat'>\n";
            
            for ($j=0; $j<count($categ); ++$j) {
                if ($categ[$j][0]==$r[3])
                $str = $str . "<option value='" . $categ[$j][0] . "' selected>" . $categ[$j][1] . "</option>\n";
                else 
                $str = $str . "<option value='" . $categ[$j][0] . "'>" . $categ[$j][1] . "</option>\n";
            
            }
            
            $str = $str . "</select>\n";
            
            
            $str = $str . "<br><button class='updateButton' type='submit'>Ενημέρωση</button>\n";
            $str = $str . "</fieldset></form>\n";
            
            $str = $str . "<form onsubmit='return validateDeleteForm()' method='post'><fieldset>\n";
            $str = $str . "<input type='hidden' name='delpid' value='$r[0]'>\n";
            $str = $str . "<button class='deleteButton' type='submit'>Διαγραφή</button>\n";
            $str = $str . "</fieldset></form>\n";
            $str = $str . "</div>\n";
        }
        
        return $str;  
    }
    
    function updateProduct($pid, $name, $timi, $cid) {
        $sql = "update products set name='$name', price=$timi, catid=$cid where id=$pid";
        //Εκτέλεση ερωτήματος
        $res = mysqli_query($this->conn, $sql);
        //Βλέπουμε πόσες εγγραφές επηρεάστηκαν από το update 
        $num = mysqli_affected_rows($this->conn); 
        return $num;
    }
    function deleteProduct($pid) {
        $sql = "delete from products where id=$pid";
        //Εκτέλεση ερωτήματος
        $res = mysqli_query($this->conn, $sql);
        //Βλέπουμε πόσες εγγραφές επηρεάστηκαν από το update 
        $num = mysqli_affected_rows($this->conn); 
        return $num;
    }    
    
    function getCategories() {
        $sql = "select * from categories";
        //Εκτέλεση ερωτήματος
        $res = mysqli_query($this->conn, $sql);
        //Δες πόσες εγγραφές επιλέχτηκαν
        $num = mysqli_num_rows($res);
        $categ = [];
        for ($i=0; $i<$num; ++$i) {
            $r = mysqli_fetch_array($res);
            $categ[$i]= [$r[0], $r[1]];
        }
        
        return $categ;
    }
    function insertProduct($pname, $pprice, $pcat) {
        $sql = "insert into products (name, price, catid) values ('$pname', $pprice, $pcat)";
        //Εκτέλεση ερωτήματος
        $res = mysqli_query($this->conn, $sql);
        //Βλέπουμε πόσες εγγραφές επηρεάστηκαν από το update 
        $num = mysqli_affected_rows($this->conn); 
        if ($num==1)
			return true;
		else 
			return false;
        
    }
        function registerUser($un, $pwd, $by) {
         // θα ελεγνο αν τ χριστι ειπαρχει ιδιαιτερα αν το email υπάρχει ήδη στη βάση
        $sql = "select * from users where username='$un'";
        $res = mysqli_query($this->conn, $sql);
        $num = mysqli_num_rows($res);
        if ($num>0) {
            return "ο χριστής εγγραφει ήδη!";
        }

            //kane hash τον κωδικό πρόσβασης πριν τον αποθηκεύσεις στη βάση
        $hashpwd = password_hash($pwd, PASSWORD_DEFAULT);    
        $sql = "insert into users (username, password, yearofbirth) values ('$un', '$hashpwd', $by)";
        //Εκτέλεση ερωτήματος
        $res = mysqli_query($this->conn, $sql);
        //Βλέπουμε πόσες εγγραφές επηρεάστηκαν από το update 
        $num = mysqli_affected_rows($this->conn); 
        if ($num==1)
			return "";
		else 
			return "Η εγγραφή απέτυχε!";
        
    }
        
    
}

