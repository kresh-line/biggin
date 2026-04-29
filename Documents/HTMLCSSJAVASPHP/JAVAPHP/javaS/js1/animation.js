
var movdiv = document.getElementById('movdiv');
var pmovdiv = document.getElementById('parentmovdiv');
var topval = pmovdiv.offsetHeight;
const stepval=-2;
var lasttime = -1;
var FPS = 30;
var FRAMEINTERVAL = 1000/FPS;

function moveDiv(executiontime){
    // αν ειναι η πρωτη φορα που τρεχει η συναρτηση ή αν εχουν περασει 33ms απο την τελευταια φορα που τρεξε
    // 33ms γιατι θελουμε να τρεχει με 30fps (1000ms/30=33.3ms)
    if (executiontime-lasttime>=FRAMEINTERVAL || lasttime==-1){
        movdiv.style.top = topval + "px";
        topval+=stepval;
        if (topval < -movdiv.offsetHeight){
            topval = pmovdiv.offsetHeight;
        }
        lasttime = executiontime;
    }
    //Zηταμε απο το browser να τρεξει την moveDiv στο επομενο frame
    requestAnimationFrame(moveDiv);
}

requestAnimationFrame(moveDiv);
/*------------------------------
*/
var gmdiv = document.getElementById('globalmovdiv');
var gmtopval = 0;
var step =2;


function moveGMD(executiontime){
    gmdiv.style.top = gmtopval + "px";
    gmtopval += step;
    if (gmtopval > window.innerHeight-gmdiv.offsetHeight || gmtopval < 0){
        step = -step;
    }
    requestAnimationFrame(moveGMD);
}

requestAnimationFrame(moveGMD);