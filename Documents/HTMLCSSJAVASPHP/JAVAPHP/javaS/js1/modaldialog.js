
var mdsc=document.getElementById("mdclose");
var md=document.getElementById("modaldialog");
var mddata=document.getElementById("mddatadiv");

function closeModal(){
 md.style.display = "none";
}
function addOpacity(){
    mddata.classList.add('setopacity');
}

mdsc.addEventListener("click", closeModal);

window.addEventListener("load", addOpacity);