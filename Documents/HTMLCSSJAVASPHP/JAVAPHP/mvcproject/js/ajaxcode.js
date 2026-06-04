// Δημιουργούμε το XMLHttpRequest object 
var req = new XMLHttpRequest(); 


function makeAjaxGet(e) {
    
    //Πάρε τις τιμές των δύο πεδίων της φόρμας
    let num1 = document.getElementById("num1").value;
    let num2 = document.getElementById("num2").value;
    let num3 = document.getElementById("num3").value;
    
    //Φτιάξε το URL που θα ζητήσουμε στο αίτημα
    let myurl = "/mvcproject/test/ajax/get/res/?n1=" + num1 + "&n2=" + num2 + "&n3=" + num3;
    
    //Δημιούργησε το XMLHttpRequest αίτημα
    req.open("GET", myurl);
    
    //Όρισε τη συνάρτηση που θα εκτελεστεί 
    //όταν το έρθει η απάντηση στο αίτημα
    req.onload = handleResponseGET;
        
    //Στείλε το αίτημα
    req.send();
    e.preventDefault();
}


function handleResponseGET() {
    if ((req.readyState == 4) && (req.status == 200)) {
            var result = req.responseText;
            document.getElementById("spanformresult").innerHTML = result;
    } 
}

var f = document.getElementById("addform");
f.addEventListener("submit", makeAjaxGet);