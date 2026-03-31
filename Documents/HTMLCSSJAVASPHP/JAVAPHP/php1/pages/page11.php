
<h2>Ανεβασμα Αρχείων</h2>
<?php
printUploadForm();

if (isset($_FILES["f"])) {
    /*
    echo "Εστειλε το αρχείο: " ;
    echo "<p>" . $_FILES["f"]["name"] . "</p>";
    echo "<p>" . $_FILES["f"]["type"] . "</p>";
    echo "<p>" . $_FILES["f"]["size"] . "</p>";
    echo "<p>" . $_FILES["f"]["tmp_name"] . "</p>";
    echo "<p>" . $_FILES["f"]["error"] . "</p>";
   */
    $from = $_FILES["f"]["tmp_name"];
    $to = "uploadefiles/" . $_FILES["f"]["name"];
    if (move_uploaded_file($from,$to))
        echo "<p>Το αρχείο ανεβηκε με επιτυχία</p>";
}
    else{
        echo "<p>Το αρχείο δεν ανέβηκε</p>";
    }
    