
//Διαλέγει το πρώτο που ταιριάζει με το selector
var cd = document.querySelector(".cookiedialog");
// Διαλέγει όλα που ταιριάζουν με το selector και άρα επιστρέφει πίνακα
var cdbuttons = document.querySelectorAll(".cdbutton");



cdbuttons[0];
cdbuttons[1];
console.log(cd, cdbuttons);

function showCD(e){
   if (!document.cookie.includes("cdconsent"))
    cd.classList.add("cdshow");
}
function hideCD(e){
    if (e.target===cdbuttons[0]){
        console.log("Συνφονω");
    document.cookie="cdconsent=true; max-age="+(60*60*24*7);
    }
    else 
        console.log("Διαφονω");
    cd.classList.remove("cdshow");
}
window.addEventListener("load",showCD);

for (i=0; i<cdbuttons.length;++i)
cdbuttons[i].addEventListener("click",hideCD);