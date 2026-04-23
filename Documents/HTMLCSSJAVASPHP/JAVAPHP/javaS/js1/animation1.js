var movdiv2 = document.getElementById('movdiv2');
var pmovdiv2= document.getElementById('parentmovdiv2');

var topval2 = pmovdiv2.offsetHeight;
var stepval2=-2;
function moveDiv2(){
    movdiv2.style.top = topval2 + "px";
    topval2+=stepval2;
    
    // αω το τοπ γινει μικροτερο απο το αρνητικο υψος του movdiv τοτε βαλε το τοπ 
    // στο υψος του pmovdiv
    if (topval2<-movdiv2.offsetHeight){
        topval2 = pmovdiv2.offsetHeight;
    }
    setTimeout(moveDiv2,33);
}

//setInterval(moveDiv2, 100);
moveDiv2();