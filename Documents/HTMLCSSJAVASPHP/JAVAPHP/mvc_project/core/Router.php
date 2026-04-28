<?php
/**
 * Router - Menaxhon routing e aplikacionit
 *
 * Përdoruesi shkruan: localhost/mvc-projekt/kontakt
 * Router shikon switch-in e routave dhe thirr controller-in përkatës
 */

class Router
{
    /**
     * Dispatch - Gjen routën dhe thirr controller/method
     *
     * @param string $url URL-ja e kërkuar
     */
    public function dispatch($url)
    {
        // Bëje URL-në lowercase — kështu RET, Ret, ret punojnë njësoj
        $url = strtolower($url);

        switch ($url) {
            // Αρχική Σελίδα - faqja e parë (default)
            case '':
            case 'home':
            case 'arxiki':
            case 'arxikiselida':
            case 'kryesore':
            case 'index':
                $controllerName = 'HomeController';
                $methodName     = 'index';
                break;

            // Παρουσίαση
            case 'paroysiasi':
            case 'parusiasi':
            case 'paroz':
            case 'presentation':
                $controllerName = 'HomeController';
                $methodName     = 'paroysiasi';
                break;

            // Προβολη Μαθητη
            case 'provolh':
            case 'provolimat':
            case 'provolimathiti':
            case 'provolh-mathiti':
                $controllerName = 'HomeController';
                $methodName     = 'provoliMathiti';
                break;

            // Εισαγωγη Μαθητη
            case 'eisagogi':
            case 'eisagogimat':
            case 'eisagogimathiti':
            case 'eisagogi-mathiti':
                $controllerName = 'HomeController';
                $methodName     = 'eisagogiMathiti';
                break;

            // Πληροφορίες
            case 'plirofoties':
            case 'pliro':
            case 'info':
                $controllerName = 'HomeController';
                $methodName     = 'plirofoties';
                break;

            // Εικονες
            case 'eikones':
            case 'eik':
            case 'images':
                $controllerName = 'HomeController';
                $methodName     = 'eikones';
                break;

            // Αγορες
            case 'agores':
            case 'agor':
            case 'shop':
                $controllerName = 'HomeController';
                $methodName     = 'agores';
                break;

            // Ανεβασμα Αρχείων
            case 'anevasma':
            case 'anev':
            case 'upload':
                $controllerName = 'HomeController';
                $methodName     = 'anevasma';
                break;

            // Kontakt
            case 'kontakt':
            case 'kontakti':
            case 'contact':
                $controllerName = 'HomeController';
                $methodName     = 'kontakt';
                break;

            // Rreth
            case 'rreth':
            case 'ret':
            case 'reth':
            case 'about':
                $controllerName = 'HomeController';
                $methodName     = 'rreth';
                break;

            default:
                $this->gabim("Faqja '{$url}' nuk u gjet - 404");
                return;
        }

        // Ngarko fajllin e controller-it
        $controllerFile = 'app/controllers/' . $controllerName . '.php';

        if (file_exists($controllerFile)) {
            require_once $controllerFile;

            // Krijo instancën e controller-it
            $controller = new $controllerName();

            // Kontrollo nëse metoda ekziston
            if (method_exists($controller, $methodName)) {
                $controller->$methodName();
            } else {
                $this->gabim("Metoda '{$methodName}' nuk u gjet në {$controllerName}");
            }
        } else {
            $this->gabim("Controller '{$controllerName}' nuk u gjet");
        }
    }

    /**
     * Shfaq faqen e gabimit
     */
    private function gabim($mesazh)
    {
        http_response_code(404);
        echo "<h1>Gabim!</h1>";
        echo "<p>{$mesazh}</p>";
        echo '<p><a href="/mvc-projekt/">Kthehu në faqen kryesore</a></p>';
    }
}
