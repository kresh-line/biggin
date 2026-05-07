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
     $this->db = "productsdb";
     $this->conn = "null";
}
     function openConnection() {
      $this->conn = mysqli_connect($this->host, $this->user, $this->pswd , $this->db);
       
}

    function closeConnection() {
        if ($this->conn != "null") {
            mysqli_close($this->conn);
        }
    }
    function getProducts() {
        $res = mysqli_query($this->conn, "SELECT * FROM products");
        $num = mysqli_num_rows($res);
        
        $str="<table class='results'>";
        for ($i=0; $i<$num; $i++) {
            $r = mysqli_fetch_array($res);
            $str .= "<tr><td>$r[0]</td><td>$r[1]</td><td>$r[2]</td><td>$r[3]</td></tr>";
        }
        $str .= "</table>";
        return $str;

    }
}



