<?php 
    require_once("views/header.php"); 
    
?>
    <div id="content">
        <h1>Φόρμα Υπολογισμού - Χωρίς AJAX</h1>
        <form action="" method='post'>
            <fieldset>
            <legend>Πρόσθεση</legend>
            <label for="num1">Αριθμός 1:</label>
            <input type="number" id="num1" name="num1" step="1" value="0" required>
            <br>
            <label for="num2">Αριθμός 2:</label>
            <input type="number" id="num2" name="num2" step="1" value="0" required>
            <br>
            <button type="submit">Υπολογισμός</button>
            </fieldset>
        </form>
        <span  class="formresult"><?php echo $GLOBALS['addresult']; ?></span>
    </div>
<?php 
    require_once("views/footer.php"); 
?>	

