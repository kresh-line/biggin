
var myimgdiv = document.getElementById("divimgs");
if (myimgdiv!=null){
 myimgdiv.addEventListener("click", changeImg);
 
 var mytargetimg = document.getElementById("targetimg");
 
}

function changeImg(e){
    
    if (e.target.nodeName=="IMG"){
        console.log(e.target.src);
        mytargetimg.src= e.target.src;
    }
}

    
//getvalue();
//printvalue();


























//alert ("Γεια σου φιλε ειμε μηνυμα JavaScript");
// x = 2;
//var v=6;
//function getvalue(){
   //let v = prompt('Δωσε τιμη:');
//}


//function printvalue(){
    //console.log(v);
//}


//function addParagraph(){
    //let v = prompt('Δωσε το κειμενο της παραγραφου:');
    //let myp = document.getElementById("ptext");
    //myp.innerHTML = myp.innerHTML + "<br>" +v ;
//}

//getvalue();
//printvalue();


