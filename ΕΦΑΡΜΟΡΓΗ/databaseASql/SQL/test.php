<!DOCTYPE html>
<html lang="el">
<head>
    <meta charset="UTF-8">
    <title>Αναζήτηση Πελάτη</title>
<style>
table, tr, td, th {border: solid 1px; border-collapse: collapse; text-align: center;}
</style>
</head>
<body>

<h2>Αναζήτηση Πελάτη</h2>

<form method="post" action="">
    <label for="customerName">Χώρα:</label>
    <input type="text" id="country" name="country" required>
    <label for="customerName">Όνομα Πελάτη:</label>
    <input type="text" id="customerName" name="customerName" required>
    <input type="submit" value="Αναζήτηση">
</form>
<br>
<table>
<tr>
<th>A/A</th><th>Κωδικός Πελάτη</th><th>Όνομα Πελάτη</th><th>First Name Πελάτη</th>
</tr>
<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $country = $_POST["country"];
    $customerName = $_POST["customerName"];

    $conn = new mysqli("localhost", "root", "", "classicmodels");

    if ($conn->connect_error) {
        die("Αποτυχία σύνδεσης: " . $conn->connect_error);
    }

    $customerNameLike = "%" . $customerName . "%";

    $stmt = $conn->prepare(
        "SELECT customerNumber, customerName, contactFirstName
         FROM customers
         WHERE LOWER(country) = LOWER(?) AND LOWER(contactFirstName) LIKE LOWER(?)"
    );

    $stmt->bind_param("ss", $country, $customerNameLike);
    $stmt->execute();

    $result = $stmt->get_result();

    if ($result->num_rows > 0) {

        $count = 0;
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . ($count+1) . "</td><td>" . $row["customerNumber"] . "</td><td>" . htmlspecialchars($row["customerName"]) . "</td><td>" . htmlspecialchars($row["contactFirstName"]) . "</td>";
            echo "</tr>";
            $count++;
        }

    } else {

        echo "<h3>Δεν βρέθηκε πελάτης με αυτό το όνομα.</h3>";

    }

    $stmt->close();
    $conn->close();
}
?>
</table>
</body>
</html>