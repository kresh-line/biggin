<?php
function showRecords($q, $fieldnum) {

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
    echo "<tr>";
    for ($j=0; $j<$fieldnum; $j++) {
        echo "<td>$row[$j]</td>";
    }
    echo "</tr>";
}

echo "</table>";
//klisei thn syndesh
mysqli_close($conn);

}
function printUploadForm() {
    ?>
   <form  enctype="multipart/form-data" action="index.php?selection=11" method="post">
    <fieldset>
        <legend> Ανέβασμα Αρχείων</legend>
        <input type="hidden" name="MAX_FILE_SIZE" value="30000">
        <label for="file">Επελεγμένο Αρχείο που θα ανεβάσεις:</label>
        <input type="file" name="f" id="f" required >
        
        <br>

         <button type="submit">Ανέβασμα</button>
        
        
    </fieldset>
</form>
<?php
}