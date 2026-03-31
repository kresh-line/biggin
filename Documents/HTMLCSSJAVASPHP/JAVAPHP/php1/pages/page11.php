
<h2>Ανεβασμα Αρχείων</h2>
<?php
printUploadForm();

if (isset($_FILES["f"])) {
    echo "Εστειλε το αρχείο: " ;


}
    else {
        echo "Δεν εστειλε το αρχείο";
    }
?>