<?php 
    require_once("views/header.php"); 
?>
    <div id="content">
        <h1>Εισαγωγή Προϊόντος</h1>
        <div class='productsformdiv'>\n";
            <form id='insertProductForm'  method='post'>
                <fieldset>
        
            <label for='pname'>Όνομα</label>
            <input type='text' id='pname' name='pname'  placeholder="Όνομα Προϊόντος">
            <label for='pprice'>Τιμή</label>
            <input type='number' id='pprice' name='pprice' min="0.00" max="9999.99" step="0.01" value='0.00' placeholder="Τιμή Προϊόντος">

            <label for='pcat$r[0]'>Κατηγορία</label>
            <select id='pcat$r[0]' name='pcat'>
            <?php
            /*
            for ($j=0; $j<count($categ); ++$j) {
               
               echo "<option value='" . $categ[$j][0] . "'>" . $categ[$j][1] . "</option>\n";
            }
           */ 
            ?>
            </select>

            <br><button class='insertButton' type='submit'>Εισαγωγή</button>
            </fieldset>
 
            </form>
        </div>
    </div>
        
<?php 
    require_once("views/footer.php"); 
?>	

