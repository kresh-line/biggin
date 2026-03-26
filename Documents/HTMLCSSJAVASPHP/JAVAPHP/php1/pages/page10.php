<?php 
$fp1 = fopen("data/products.txt", "r");
    
while ($p=fgets($fp1)){
    $t=fgets($fp1);
    echo "<p>$p $t</p>";
}

//Kleinv to arxeio
fclose($fp1);

?>