<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>MVC Projekt</title>
        <link rel="stylesheet" type="text/css" href="/mvc_project/css1/format.css">
        <link rel="stylesheet" type="text/css" href="/mvc_project/css1/extra.css">
    </head>
    <body>
        <div id="main">

            <div id="header">
                <div id="logo">LOGO</div>
            </div><!-- end header -->

            <div id="middle">

                <div id="menu">
                    <ul class="verticalmenu">
                        <li><a href="/mvc_project/index.php">Αρχική Σελίδα</a></li>
                        <li><a href="/mvc_project/index.php?selection=2">Παρουσίαση</a></li>
                        <li><a href="/mvc_project/index.php?selection=3">Προβολη Μαθητη</a></li>
                        <li><a href="/mvc_project/index.php?selection=7">Εισαγωγη Μαθητη</a></li>
                        <li><a href="/mvc_project/index.php?selection=4">Πληροφορίες</a></li>
                        <li><a href="/mvc_project/index.php?selection=5">Εικονες</a></li>
                        <li><a href="/mvc_project/index.php?selection=10">Αγορες</a></li>
                        <li><a href="/mvc_project/index.php?selection=10">Ανεβασμα Αρχείων</a></li>
                    </ul>
                </div>

                <div id="content">
                    <?php
                    if (isset($pageFile) && file_exists($pageFile)) {
                        include $pageFile;
                    } elseif (isset($_GET["selection"])) {
                        if ($_GET["selection"] == 1) {
                            include("app/views/pages/page1.php");
                        } elseif ($_GET["selection"] == 2) {
                            include("app/views/pages/page2.php");
                        } elseif ($_GET["selection"] == 3) {
                            include("app/views/pages/page3.php");
                        } elseif ($_GET["selection"] == 4) {
                            include("app/views/pages/page4.php");
                        } elseif ($_GET["selection"] == 5) {
                            include("app/views/pages/page5.php");
                        } elseif ($_GET["selection"] == 6) {
                            include("app/views/pages/page6.php");
                        } elseif ($_GET["selection"] == 7) {
                            include("app/views/pages/page7.php");
                        } elseif ($_GET["selection"] == 8) {
                            if (isset($_SESSION["user"])) {
                                echo "<h3>Καλώς ήρθες χρήστη!</h3>";
                            }
                            include("app/views/pages/page1.php");
                        } elseif ($_GET["selection"] == 9) {
                            echo "<h3>Έχεις αποσυνδεθεί!</h3>";
                        } elseif ($_GET["selection"] == 10) {
                            include("app/views/pages/page10.php");
                        } elseif ($_GET["selection"] == 11) {
                            include("app/views/pages/page11.php");
                        } else {
                            echo "Δεν βρέθηκε επιλογή";
                        }
                    }
                    ?>

                </div>

            </div><!-- end middle -->

            <div id="footer"></div>

        </div><!-- end main -->

        <script src="/mvc_project/js1/main.js"></script>
    </body>
</html>
