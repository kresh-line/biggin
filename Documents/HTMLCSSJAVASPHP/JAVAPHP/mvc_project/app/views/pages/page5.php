
<?php
if(isset($_SESSION["user"])){
if (isset($_SESSION["images"])) 
$_SESSION["images"]++;
else {
    $_SESSION["images"]=1;
}
echo "<p> Ειναι η " . $_SESSION["images"] . "η φορα </p>";
}
?>

<?php
if (isset($_SESSION["user"])) {
$carimgs = ["car1.1.jpg","car2.2.jpg","car3.3.jpg","car4.4.jpg","car5.5.jpg"];

$carnum = count($carimgs);
$platos = 100/$carnum;
echo "<div id='divimgs'>";
for ($i=0;$i<$carnum;$i++){
    echo "<img style='width:$platos%; cursor:pointer;' src='img/car/" . $carimgs[$i] . "' onclick='showCar(this.src)'>";
}
echo "</div>";
?>

<div id='carpreview' style='margin-top:10px;'>
    <img id='bigcar' src='' style='display:none; max-width:100%;'>
</div>

<script>
function showCar(src) {
    var img = document.getElementById('bigcar');
    img.src = src;
    img.style.display = 'block';
}
</script>
<?php
} else {
    echo "<p>Δεν έχεις δικαίωμα. Παρακαλώ κάνε login.</p>";
}
?>
