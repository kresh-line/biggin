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