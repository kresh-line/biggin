<?php
/**
 * HomeController - Controller kryesor i faqes
 *
 * Çdo metodë ngarkon view-n përkatëse
 */

class HomeController
{
    /**
     * Faqja kryesore - localhost/mvc-projekt/home
     */
    public function index()
    {
        $data = [
            'titulli' => 'Faqja Kryesore',
            'mesazhi' => 'Mirë se erdhe në projektin MVC!'
        ];

        require 'app/views/home.php';
    }

    // Παρουσίαση - /mvc_project/paroysiasi
    public function paroysiasi()
    {
        $pageFile = 'app/views/pages/page2.php';
        require 'app/views/home.php';
    }

    // Προβολη Μαθητη - /mvc_project/provolh
    public function provoliMathiti()
    {
        $pageFile = 'app/views/pages/page3.php';
        require 'app/views/home.php';
    }

    // Εισαγωγη Μαθητη - /mvc_project/eisagogi
    public function eisagogiMathiti()
    {
        $pageFile = 'app/views/pages/page7.php';
        require 'app/views/home.php';
    }

    // Πληροφορίες - /mvc_project/plirofoties
    public function plirofoties()
    {
        $pageFile = 'app/views/pages/page4.php';
        require 'app/views/home.php';
    }

    // Εικονες - /mvc_project/eikones
    public function eikones()
    {
        $pageFile = 'app/views/pages/page5.php';
        require 'app/views/home.php';
    }

    // Αγορες - /mvc_project/agores
    public function agores()
    {
        $pageFile = 'app/views/pages/page10.php';
        require 'app/views/home.php';
    }

    // Ανεβασμα Αρχείων - /mvc_project/anevasma
    public function anevasma()
    {
        $pageFile = 'app/views/pages/page11.php';
        require 'app/views/home.php';
    }

    // Faqja e kontaktit - /mvc_project/kontakt
    public function kontakt()
    {
        $data = [
            'titulli' => 'Na Kontaktoni',
            'email'   => 'info@example.com'
        ];

        require 'app/views/kontakt.php';
    }

    /**
     * Faqja Rreth Nesh - localhost/mvc-projekt/rreth
     */
    public function rreth()
    {
        $data = [
            'titulli' => 'Si funksionon MVC?',
        ];

        require 'app/views/rreth.php';
    }
}
