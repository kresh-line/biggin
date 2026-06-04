
var req = new XMLHttpRequest();


function makeajaxget(e) {
    e.preventDefault();
    let num1 = document.getElementById("num1").value;
    let num2 = document.getElementById("num2").value;
    let url = "/mvcproject/test/ajax/get/res/?n1=" + num1 + "&n2=" + num2;
    req.open("GET", url, true);
    req.onload = handleResponseGET
    req.send();
}

function handleResponseGET() {
    if ((req.readyState == 4) && (req.status == 200)) {
        var response = req.responseText;
        document.getElementById("spanformresult").innerHTML = response;
    }
}