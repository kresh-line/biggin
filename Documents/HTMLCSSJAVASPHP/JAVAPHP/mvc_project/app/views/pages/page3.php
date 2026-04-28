<!-- <h2>Μαθητες </h2> -->

<?php
/*
$lines = file("data/mathites.txt", FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

echo "<table border='1'>";
echo "<tr><th>A.M</th><th>Ονομα/Επώνυμο</th></tr>";

for ($i = 0; $i < count($lines); $i += 3) {
    $am       = $lines[$i];
    $eponimo  = $lines[$i + 1];
    $onoma    = $lines[$i + 2];
    echo "<tr>";
    echo "<td>" . $am . "</td>";
    echo "<td>" . $eponimo . " " . $onoma . "</td>";
    echo "</tr>";
}

echo "</table>";
*/
?>









<h2>Μαθητές</h2>

<?php
if (isset($_SESSION["numshow"])) 
$_SESSION["numshow"]++;
else {
    $_SESSION["numshow"]=1;
}
echo "<p> Ειναι η " . $_SESSION["numshow"] . "η φορα </p>";
//Ανοιγο το αρχειο για διαβασμα
if (isset($_SESSION["user"])) {
$fp1 = fopen("data/mathites.txt", "r");
?>

<table class="results">
    <tr><th>Αρ. Μητρωου</th><th> Επονιμο</th><th>Ονομα</th><th>Βαθμος</th></tr>
    <?php
while (fscanf($fp1, "%d", $x) == 1){
fscanf($fp1, "%s", $n);
fscanf($fp1, "%s", $v);
fscanf($fp1, "%d", $ex);
echo"<tr><td>$x</td><td>$n</td><td>$v</td><td>$ex</td></tr>\n";
}
echo "</table>";

//Kleinv to arxeio
fclose($fp1);

} else  {
      echo "<p>Δεν έχεις δικαίωμα να δεις τους μαθητές. Παρακαλώ κάνε login-in.</p>";
}
?>