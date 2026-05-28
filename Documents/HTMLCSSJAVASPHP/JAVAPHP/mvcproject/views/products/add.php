<?php 
    require_once("views/header.php"); 
?>
    <div id="content">
        <h1>Εισαγωγή Προϊόντος</h1>
        <?php if ($GLOBALS['username'] != null): ?>
        <?php
            if (isset($_POST["pname"]) && $_POST["pname"] !== "")
                echo "<p> Στάλθηκε η φόρμα </p>";
            else
                echo "<p> Δεν έστειλες το φόρμα </p>";
        ?>
        <div class='productsformdiv'>
            <form id='insertProductForm' method='post' novalidate>
                <fieldset>

            <label for='pname'>Όνομα</label>
            <input type='text' id='pname' name='pname'  placeholder="Όνομα Προϊόντος" required><br>
            <label for='pprice'>Τιμή</label>
            <input type='number' id='pprice' name='pprice' min="0.00" max="9999.99" step="0.01" value='0.00' required><br>

            <label for='pcat'>Κατηγορία</label>
            <select id='pcat' name='pcat' required>
            <?php

            for ($j=0; $j<count($GLOBALS['categories']); ++$j) {

               echo "<option value='" . $GLOBALS['categories'][$j][0] . "'>" . $GLOBALS['categories'][$j][1] . "</option>\n";

               }

            ?><br>
            </select>


            <button class='insertButton' type='submit'>Εισαγωγή</button><br>
            <span class="errormsg" id="ifem"></span>
            </fieldset>

            </form>
        </div>
        <script src="/mvcproject/js/jscode.js"></script>
        <?php else: ?>
        <p>Δεν έχεις κάνει σύνδεση. Παρακαλώ συνδέσου για να εισάγεις προϊόν.</p>
        <?php endif; ?>
    </div>
<?php 
    require_once("views/footer.php"); 
?>	

