<?php 
    require_once("views/header.php"); 
?>
    <div id="content">
        <h1>Εγχειριδια</h1>


        <?php
        $f = scandir("docs/");
        for ($i=2; $i < count($f); ++$i)
            echo $f[$i] . "<br>";

        ?>
    </div>
<?php 
    require_once("views/footer.php"); 
?>