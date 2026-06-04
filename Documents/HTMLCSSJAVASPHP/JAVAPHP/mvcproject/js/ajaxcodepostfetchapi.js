//var req = new XMLHttpRequest();
//var clickvar = 0;
//function makePostRequest(e) {
    /*event.preventDefault();
    alert("click");*/
    /*let num1 = document.getElementById("num1").value;
    let num2 = document.getElementById("num2").value;
    let num3 = document.getElementById("num3").value;
    let myurl = "/mvcproject/test/ajax/post/res/";
    req.open("POST", myurl);
     
    let formData = new FormData();
    formData.append("num1", num1);
    formData.append("num2", num2);
    formData.append("num3", num3);
    req.onload = handleResponsePOST;
    req.send(formData);
}
function handleResponsePOST() {
    if ((req.readyState == 4) && (req.status == 200)) {
            var result = req.responseText;
            document.getElementById("spanformresult").innerHTML = result;
    }
}*/
// prepi auti sinarti me async  await kai fetch API
async function makePostRequest(e) {
    let num1 = document.getElementById("num1").value;
    let num2 = document.getElementById("num2").value;
    let num3 = document.getElementById("num3").value;

    let formData = new FormData();
    formData.append("num1", num1);
    formData.append("num2", num2);
    formData.append("num3", num3);
    let response = await fetch("/mvcproject/test/ajax/post/res/",
     {
        method: "POST",
        body: formData
    });

    let result = await response.text();
    document.getElementById("spanformresult").innerHTML = result;
}