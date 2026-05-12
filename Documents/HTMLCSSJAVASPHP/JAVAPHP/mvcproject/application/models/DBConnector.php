<?php 
class DBConnector {
    private $host; // to localhost είναι το όνομα του server που τρέχει η βάση δεδομένων
    private $user; // to onoma xristi pou exei o server gia na kanei connect stin vasi
    private $pswd; // to kalitero kwdikos pou exei o xristis
    private $db; // to onoma tis vasis pou tha xrisimopoioume
    private $conn; // to connection object pou tha xrisimopoioume gia na kanoume queries stin vasi

    function __construct() {
     $this->host = "localhost";
     $this->user = "root";
     $this->pswd = "";
     $this->db = "productsdb";//productsdb në shkoll
     $this->conn = null;
}
     function openConnection() {
      $this->conn = mysqli_connect($this->host, $this->user, $this->pswd , $this->db);
}

    function closeConnection() {
        if ($this->conn !== null) {
            mysqli_close($this->conn);
            $this->conn = null;
        }
    }

    function getProducts() {
        if ($this->conn === null) {
            return "<p>Gabim: lidhja me bazën e të dhënave nuk është hapur.</p>";
        }
        $sql = "SELECT products.id, products.name, products.price, categories.name FROM products INNER JOIN categories ON products.catid = categories.id";
        $res = mysqli_query($this->conn, $sql);
        $num = mysqli_num_rows($res);

        $str = "<table class='results'>";
        $str .= "<tr><th>ID</th><th>Name</th><th>Price</th><th>Category</th></tr>";
        for ($i = 0; $i < $num; $i++) {
            $r = mysqli_fetch_array($res);
            $str .= "<tr><td>$r[0]</td><td>$r[1]</td><td>$r[2]</td><td>$r[3]</td></tr>";
        }
        $str .= "</table>";
        return $str;
    }
    function getProductsAsFroms() {
        if ($this->conn === null) {
            return "<p>Λαθος.</p>";
        }
        $sql = "SELECT * from products";
        $res = mysqli_query($this->conn, $sql);
        $num = mysqli_num_rows($res);

        $str = "<table class='results'>";
        $str .= "<tr><th>ID</th><th>Name</th><th>Price</th><th>Category</th></tr>";
        for ($i = 0; $i < $num; $i++) {
            $r = mysqli_fetch_array($res);
            $str = $str . "<form method='post'><fieldset>\n";
            $str = $str . "<label for='pid'> κωδικος</label>\n";
            $str = $str . "<input type='text' id='pid' name='pid' value='$r[0]'>\n";
            $str = $str . "<label for='pname'>Ονομα</label>";
            $str = $str . "<input type='text' id='pname' name='pname' value='$r[1]'>\n";
            $str = $str . "<label for='pprice'>Τιμη</label>\n";
            $str = $str . "<input type='number' id='pprice' name='pprice' value='$r[2]'>\n";
            $str = $str . "<label for='pcat'> Κατιγορια</label>\n";
            $str = $str . "<input type='text' id='pcat' name='pcat' value='$r[3]'>\n";
            $str = $str . "<button type='submit'>Ενιμεροσι </button>\n";
            $str = $str . "<input type='hidden' name='delpit' value='$r[0]'>\n";
            $str = $str . "<button type='submit'>delete </button>\n";
            $str = $str . " </fieldset></form>\n";
        }
        return $str;
    }

}


