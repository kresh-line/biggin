//alert("Γεια σου φιλε ειμε μηνυμα JavaScript");
/*
 * παρε το ετικετα που εχει id="ptext" και εκχωρησε το στην μεταβλητη myp
 */
var myp = document.getElementById("ptext");
//παρε το ετικετα που εχει id="list1" και εκχωρησε το στην μεταβλητη mylists
var mylist = document.getElementById("list1");
//var mydiv = document.getElementById("colorediv");
//παρε το ετικετα που εχει id="div1" και εκχωρησε το στην μεταβλητη mydiv
var mydiv = document.getElementById("div1");
mydiv.addEventListener("click", changeBGColor);
var myimgdiv = document.getElementById("divimgs");
 myimgdiv.addEventListener("click", changeImg);
 
 var mytargetimg = document.getElementById("targetimg");
 var mytargetlink = document.getElementById("imgref");
var myrandomnumdiv = document.getElementById("randomnum");
myrandomnumdiv.addEventListener("click", createRandomNum);
var v=3;

function changeImg(e){
    
    if (e.target.nodeName=="IMG")
    console.log(e.target.src);
    mytargetimg.src= e.target.src;
     mytargelink.href= e.target.getAttribute("data-src");
}
function changeBGColor(e) {
    //console.log(e);
    if (e.target.nodeName=="DIV")
        alert ("Πατησε σε div");
    else 
        if (e.target.nodeName=="P")
            alert ("Πατησε σε παραγραφο");
    else 
        alert ("Πατησε σε image");
}

/*function getvalue() {
    let v = prompt('Δωσε τιμη:');
    
}
    */
   // arrow function 
let getvalue = () => {
    let v = prompt('Δωσε τιμη:');
}

function printvalue() {
    console.log(v);
}
/*
 Συνάρτηση που ανοίγει ένα παράθυρο (καλεί την prompt), παίρνει ένα κείμενο
 από τον χρήστη και το προσθέτει στο τέλος του στοιχείου myp
 */
function addParagraph() {
    let v = prompt('Δωσε το κειμενο της παραγραφου');
    myp.innerHTML = myp.innerHTML + "<br>" + v;
}
/*
 Συνάρτηση που ανοίγει ένα παράθυρο (καλεί την prompt), παίρνει ένα κείμενο
 από τον χρήστη και το προσθέτει σαν <li> στο στοιχείου myp
 */
function addListElement() {
    let v = prompt('δωσε το στοιχει της λιστας:');
    mylist.innerHTML = myp.innerHTML + "<li>" + v + "</li>";
    }
    /*
        Συνάρτηση που παίρνει 2 παραμέτρους:
        c: Είναι ένα string που αντιστοιχεί στο χρώμα που θέλουμε
        a: Είναι το αντικείμενο του οποίου το χρώμα θα αλλάξφυμε
    */
    function changeColor(c,a) {
        a.style.color = c;
        
    }
     function createRandomNum(e) {
        let numForm =parseInt(document.getElementById("numfrom").value);
        let numTo = parseInt(document.getElementById("numto").value);

        //alert(`Η τινη ειναι μεταξυ ${numForm} και ${numTo}`);

        let myp = document.getElementById("rnp");
        if (numTo<=numForm){
            myp.innerHTML = "Το ανωτερο οριο πρεπει να ειναι μεγαλυτερο απο το κατωτερο οριο";
           
        }
        else {
             
        
        //δημιουργει ενα τυχαιο αριθμο μεταξυ 0 και 1
        let num = Math.floor(numForm + Math.random() * (numTo - numForm));
        //παρε το στοιχειο με id rnp και εκχωρησε το στην μεταβλητη myp
        
        // γραψε τον τυχαιο αριθμο μεσα στο στοιχειο myp
        myp.innerHTML = num;
        
     }
    
    }







/*

getvalue();
printvalue();


























alert ("Γεια σου φιλε ειμε μηνυμα JavaScript");
 x = 2;
var v=6;
function getvalue(){
   let v = prompt('Δωσε τιμη:');
}


function printvalue(){
    //console.log(v);
}


function addParagraph(){
    let v = prompt('Δωσε το κειμενο της παραγραφου:');
    let myp = document.getElementById("ptext");
    myp.innerHTML = myp.innerHTML + "<br>" +v ;
}

getvalue();
printvalue();*/
