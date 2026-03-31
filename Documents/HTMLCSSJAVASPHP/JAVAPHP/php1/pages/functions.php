<?php 
function showProducts($q) {

// Create connection
// με οναμα χρήστη root και χωρίς κωδικό πρόσβασης και με όνομα βάσης δεδομένων productsdb
$conn = mysqli_connect("localhost", "root", "", "productsdb");


$res = mysqli_query($conn, $q);

//δες ποσες εγγραφές υπάρχουν
$num = mysqli_num_rows($res);
echo "<p>$num</p>\n";
echo "<table class='results'>";
for ($i=0; $i<$num; $i++) {
    $row = mysqli_fetch_array($res);
    echo "<tr><td>$row[0]</td><td>$row[1]</td><td>$row[2]</td></tr>";

    //echo "<p>" . $row["id"] . " " . $row["name"] . " " . $row["price"] . "</p>";
}
echo "</table>";
//klisei thn syndesh
mysqli_close($conn);


}

