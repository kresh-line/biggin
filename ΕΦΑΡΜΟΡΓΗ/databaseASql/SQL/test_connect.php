<?php
$conn = mysqli_connect("localhost", "root", "", "classicmodels");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

echo "Connected to MySQL<br />";
echo "Connected to Database";
?>