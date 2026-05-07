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
}
