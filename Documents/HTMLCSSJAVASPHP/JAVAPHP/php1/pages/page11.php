
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
        echo "<p>Το αρχείο ανεβηκε με επιτυχία!</p>";
}
    else{
         switch ($_FILES["f"]["error"]) {
         case UPLOAD_ERR_INI_SIZE:
            echo "<h3>The uploaded file exceeds the upload_max_filesize directive in php.ini.</h3>";
            break;
         case UPLOAD_ERR_FORM_SIZE:
            echo "<h3>The uploaded file exceeds the MAX_FILE_SIZE directive in the HTML form.</h3>";
            break;
         case UPLOAD_ERR_PARTIAL:
            echo "<h3>The file was only partially uploaded.</h3>";
            break;
         case UPLOAD_ERR_NO_FILE:
            echo "<h3>No file was uploaded.</h3>";
            break;
         case UPLOAD_ERR_NO_TMP_DIR:
            echo "<h3>Missing a temporary folder.</h3>";
            break;
         case UPLOAD_ERR_CANT_WRITE:
            echo "<h3>Failed to write file to disk.</h3>";
            break;
         case UPLOAD_ERR_EXTENSION:
            echo "<h3>File upload stopped by extension.</h3>";
            break;
         default:
            echo "<h3>Unknown upload error.</h3>";
      }
    }
    