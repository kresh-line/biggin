<?php 
// Create connection
// με οναμα χρήστη root και χωρίς κωδικό πρόσβασης και με όνομα βάσης δεδομένων productsdb
$conn = mysqli_connect("localhost", "root", "", "productsdb");


$res = mysqli_query($conn, "select * from products");

//δες ποσες εγγραφές υπάρχουν
$num = mysqli_num_rows($res);
echo "<p>$num</p>";
for ($i=0; $i<$num; $i++) {
    $row = mysqli_fetch_array($res);
    //echo "<p>" . $row["id"] . " " . $row["name"] . " " . $row["price"] . "</p>";
}

//klisei thn syndesh
mysqli_close($conn);

?>