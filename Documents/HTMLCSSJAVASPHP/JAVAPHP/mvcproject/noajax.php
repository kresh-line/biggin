<?php 
    require_once("views/header.php"); 
?>
    <div id="content">
        <h1> φορμα Υπολογισμού - Χωρις AJAX</h1>
        <form method="post">
            <fieldset>
                <legend>Προσθεσι</legend>
            <label for="num1">Αριθμός 1:</label>
            <input type="number" id="num1" name="num1" step="1" value="0" required><br>
            
            <label for="num2">Αριθμός 2:</label>
            <input type="number" id="num2" name="num2" step="1" value="0" required><br>
            
            <button type="submit">Υπολογισμός</button>
            </fieldset>
        </form>
    </div>
<?php 
    require_once("views/footer.php"); 
?>	

