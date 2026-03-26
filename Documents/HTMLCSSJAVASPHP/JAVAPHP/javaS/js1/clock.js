var myspan = document.getElementById("myclock");

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
    
    myspan.innerHTML = h + ":" + m + ":" + s;
    
}

setInterval(myclock,  1000);