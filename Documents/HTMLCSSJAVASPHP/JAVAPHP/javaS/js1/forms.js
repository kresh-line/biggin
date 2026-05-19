var f = document.getElementById("formtocheck");

f.addEventListener("submit", checkSubmission);

var errormgs = document.getElementById("formerrormsg");

function checkSubmission(e) {
    let msgstr = "";
    if (f.elements['fruit'].checkValidity() === false) {
        if (f.elements['fruit'].validity.patternMismatch === true) {
            msgstr = msgstr + "Παρακαλώ επιλέξτε μπανάνα ή κεράσι.<br>";
        }
        if (f.elements['fruit'].validity.valueMissing === true) {
            msgstr = msgstr + "Παρακαλώ επιλέξτε ένα φρούτο.<br>";
        }
    }

    if (f.elements['email'].checkValidity() === false) {
        msgstr = msgstr + "bale to email.<br>";
    } else if (f.elements['email'].value.endsWith("@gmail.com") === false) {
        msgstr = msgstr + "Το email πρέπει να τελειώνει σε @gmail.com.<br>";
    }

    let num = 0;

    if (f.elements['choice1'].checked === true) {
        num++;
    }
    if (f.elements['choice2'].checked === true) {
        num++;
    }
    if (f.elements['choice3'].checked === true) {
        num++;
    }
    if (num < 2) {
        msgstr = msgstr + "Παρακαλώ επιλέξτε τουλάχιστον 2 επιλογές.<br>";
    }

// let num = 0;

    if (f1.elements['choice1'].checked === true) 
        num++;
    
    if (f1.elements['choice2'].checked === true) 
        num++;
    
    if (f1.elements['choice3'].checked === true) 
        num++;
    
    if (num < 2) {
        msgstr = msgstr + "Παρακαλώ επιλέξτε τουλάχιστον 2 επιλογές.<br>";
    }


    if (msgstr !== "") {
        errorform1.innerHTML = msgstr;
        e.preventDefault();
    }
}

/*f.elements['fruit'].addEventListener("input", checkFruit);
function checkFruit(e) {
    f.elements['fruit'].setCustomValidity("");
    if (f.elements['fruit'].checkValidity() === false) {
        f.elements['fruit'].setCustomValidity("mono  kerasi kai krasi ");
    }
}*/

/*f.elements['fruit'].addEventListener("input", checkFruit);
function checkFruit(e) {
    f.elements['fruit'].setCustomValidity("");
    if (f.elements['fruit'].checkValidity() === false) {
        f.elements['fruit'].setCustomValidity("mono  kerasi kai krasi ");
    }
}
*/
var f1 = document.getElementById("form1");

f1.addEventListener("submit", checkform1);
var errorform1 = document.getElementById("errorform1");
function checkform1(e) {
    let msgstr = "";
    if (f.elements['email'].value.endsWith("@gmail.com") === false) {
        msgstr = msgstr + "be email mono sto @gmail.com.<br>";
    }
    if (msgstr !== "") {
        errorform1.innerHTML = msgstr;
        e.preventDefault();
    }
}