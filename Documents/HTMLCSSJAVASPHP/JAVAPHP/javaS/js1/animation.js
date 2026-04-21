/*var movdiv = document.getElementById('movdiv');
var pmovdiv = document.getElementById('parentmovdiv');

var topval = pmovdiv.offsetHeight;
var stepval=-5;
function moveDiv(){
    movdiv.style.top = topval + "px";
    topval+=stepval;

    // αω το τοπ γινει μικροτερο απο το αρνητικο υψος του movdiv τοτε βαλε το τοπ 
    // στο υψος του pmovdiv
    if (topval<-movdiv.offsetHeight){
        topval = pmovdiv.offsetHeight;
    }
    setTimeout(moveDiv,100);
}

//setInterval(moveDiv, 100);
moveDiv();*/

var movdiv = document.getElementById('movdiv');
var pmovdiv = document.getElementById('parentmovdiv');

var topval = pmovdiv.offsetHeight;
var stepval=-5;
function moveDiv(){
    movdiv.style.top = topval + "px";
    topval+=stepval;

    // αω το τοπ γινει μικροτερο απο το αρνητικο υψος του movdiv τοτε βαλε το τοπ 
    // στο υψος του pmovdiv
    if (topval<-movdiv.offsetHeight){
        topval = pmovdiv.offsetHeight;
    }
    setTimeout(moveDiv,100);
}

//setInterval(moveDiv, 100);
moveDiv();