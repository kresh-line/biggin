var parDiv = document.getElementById("parentmovdiv3");
var movDiv = document.getElementById("movdiv3");
//var a = 1;
var lastTime = -1;
var FPS = 15;
var topval = parDiv.offsetHeight;
var topstep = -5;

function myanim(tm){
    if(lastTime==-1){
        lastTime = tm;
        //console.log(a++);    
        movDiv.style.top = "" + topval + "px";
        topval += topstep;
    }
    else if (tm - lastTime>=1000/FPS){
         lastTime = tm;
         movDiv.style.top = "" + topval + "px";
         topval += topstep;
        //console.log(a++);  
    }
    // an to top val exei ftasei sto -height tou movdiv tote to topval gurnaei sto height tou parDiv
    if (topval <= -movDiv.offsetHeight){
        topval = parDiv.offsetHeight;
    }
    requestAnimationFrame(myanim);
}
requestAnimationFrame(myanim);