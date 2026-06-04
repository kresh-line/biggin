<?php 
    require_once("views/header.php"); 
?>
    <div id="content">
        <h1>Εισαγωγή Προϊόντος</h1>
        <?php
        //Αν έχει κάνει login εμφάνισε τα απαραίτητα
         if ($GLOBALS['username']!=null) {
            if ($_GLOBALS["insertProduct"]) {
                if ($_GLOBALS["insertProductResult"])
                    echo "<p>Η εισαγωγή του προϊόντος έγινε!</p>";
                else 
                    echo "<p>Η εισαγωγή του προϊόντος απέτυχε!</p>"; 
            }
        
        ?>
        
        <div class='productsformdiv'>
        <form id='insertProductForm' enctype="multipart/form-data"  method='post'>
            <fieldset>

            <label for='pname'>Όνομα: </label>
            <input type='text' id='pname' name='pname' placeholder='Γράψε το όνομα του προϊόντος ...' required>
            <label for='pprice'>Τιμή</label>
            <input type='number' id='pprice' name='pprice' min='0.00' max='2000.00' step="0.01" value="0.00" required><br>
            
            <label for='pcat'>Κατηγορία</label>
            <select id='pcat' name='pcat' required>
            
            <?php
            
            for ($j=0; $j<count($GLOBALS['categories']); ++$j) {
                echo "<option value='" . $GLOBALS['categories'][$j][0] . "'>" . $GLOBALS['categories'][$j][1] . "</option>\n";
            }
           
            ?>
            </select>
            <br>
            <input type="hidden" name="MAX_FILE_SIZE" value="30000">
            <label for="f">Φωτογραφία προϊόντος: </label> 
            <input type="file" name="f" id="f" required>
            <br>
            <button class='insertButton' type='submit'>Εισαγωγή</button>
            </fieldset>
        </form>
        </div>
        <span id="ifem" class="errormsg"></span>
        
        <script src="/mvcproject/js/jscode.js"></script>
    </div>
<?php 

         }
         else //Αν δεν έχει κάνει login
             echo "<p>Πρέπει να κάνετε σύνδεση για να χρησιμοποιήσετε αυτή τη σελίδα!</p>";
         
    require_once("views/footer.php"); 
?>	

