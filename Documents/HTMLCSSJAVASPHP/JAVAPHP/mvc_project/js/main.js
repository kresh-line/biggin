
var myimgdiv = document.getElementById("divimgs");
if (myimgdiv!=null) {
    myimgdiv.addEventListener("click", changeImg);
    var mytargetimg = document.getElementById("targetimg");
 }
 
function changeImg(e) {
    if (e.target.nodeName=="IMG") {
        console.log(e.target.src);
        mytargetimg.src = e.target.src;
    }
}
