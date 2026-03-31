<?php
include 'functions.php';
showRecords("SELECT * FROM categories", 2);
showRecords("SELECT * FROM products", 3);
showRecords("SELECT * FROM customers", 2);
?>