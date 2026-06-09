var colorValue = 0;

function myclock() {
    let hm = new Date();
    let h = hm.getHours();
    let m = hm.getMinutes();
    let s = hm.getSeconds();
    if (s<10)
        s = "0" + s;
    if (m<10)
        m = "0" + m;
    if (h<10)
        h = "0" + h;
    
    $("#myclock").html(h + ":" + m + ":" + s);
    if (colorValue == 0) {
        $("#myclock").css({"color": "red" , "font-size": "1.05em"});
        colorValue = 1;

    }
    else {
        $("#myclock").css({"color": "green" , "font-size": "2.00em"});
        colorValue = 0;
    }
}

setInterval(myclock,  1000);

var platos = 500;
var stap = 100;
$("#testing").click(imgclick);
function imgclick(e) {
    //alert("You clicked the image");
    let x = platos+"px";
    $("#testing").css({"width": x});
    platos = platos - stap;
    if (platos < 100) {
        platos = 200;
        stap = -stap;
    }
    else if (platos > 500) {
        platos = 400;
        stap = -stap;
    }
}
$("#testing").css({"position": "relative"});
$("#testing").mouseover(imganim);
function imganim(e) {
     $("#testing").animate({"width": "100px", right: "100px"}, 3000);
}
$("#testing").mouseout(imganim2);
function imganim2(e) {
     $("#testing").animate({"width": "500px"}, 5000);
}