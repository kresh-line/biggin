class viewportAdvertising {

    constructor(id, step,topval, leftval, widthval, bgcolor, opacity) {
        this.id = id;
        this.step = step;
        this.gmdiv = document.getElementById(id);
        this.val = 0;
        this.widthval = widthval;
        this.bgcolor = bgcolor;
        this.opacity = opacity;
        this.execAnim = true;
        this.gmdiv.style.left = leftval + "px";
        this.gmdiv.style.top = topval + "px";
        this.setCSS();
        this.gmdiv.addEventListener("mouseover", () => this.stopAnim());
        this.gmdiv.addEventListener("mouseout", () => this.startAnim());
    }
    setCSS(){
        this.gmdiv.style.position = "fixed";
        //this.gmdiv.style.zIndex = 100;
        this.gmdiv.style.width = this.widthval + "px";
        this.gmdiv.style.backgroundColor = this.bgcolor;
        //this.gmdiv.style.backgroundColor = "white";
        this.gmdiv.style.opacity = this.opacity;
    }
    animleft() {
        if (this.execAnim) {
            this.gmdiv.style.left = this.val + "px";
            this.val += this.step;
        }
        if (this.val > window.innerWidth - this.gmdiv.offsetWidth || this.val < 0) {
            this.step = -this.step;
        }
        requestAnimationFrame(() => this.animleft());
    }
    animtop() {
       
        if (this.execAnim) {
            this.gmdiv.style.top = this.val + "px";
            this.val += this.step;
        }
        if (this.val > window.innerHeight - this.gmdiv.offsetHeight || this.val < 0) {
            this.step = -this.step;
        }
        requestAnimationFrame(() => this.animtop());
    }
    stopAnim() {
        this.execAnim = false;
    }
    startAnim() {
        this.execAnim = true;
    }
}

class cleverContainer {
    constructor(classname) {

        this.elems = document.querySelectorAll(classname);

        for (let i = 0; i < this.elems.length; i++) {
            this.elems[i].addEventListener('click', (ev) => this.changeElem(ev));
        }
    }

    changeElem(ev) {
        ev.target.style.boxShadow = "10px 5px 5px red";
        let width = ev.target.offsetWidth;
        ev.target.style.width = (width + 20) + "px";
        if (ev.target.getAttribute("data-MGS") != null)
            alert(ev.target.getAttribute("data-MGS"));
    }
}

class parentAdvertising {

    constructor(id, pid, spepval, fps, val ) {
        this.id = id;
        this.pid = pid;
        this.stepval = spepval;
        this.fps = fps;
        this.val = val;
        this.frameInerval = 1000/fps;
        this.firstTime = -1;
        this.mee= document.getElementById(id);
        this.myparent = document.getElementById(pid);
        this.topval = this.myparent.offsetHeight;
        //requestAnimationFrame(() => this.anim());
        //this.moveDiv();
    }
    // t ειναι ο χρονος που περναει απο την αρχη της εκτελεσης του script μεχρι την στιγμη που τρεχει η moveDiv
    // this.lastTime ειναι ο χρονος που τρεχει η moveDiv την τελευταια φορα
    anim(t){
        if (this.firstTime == -1) this.firstTime = t;
        if (t - this.firstTime >= this.frameInerval){
            this.mee.style.top = this.topval + "px";
            this.topval += this.stepval;
            this.firstTime = t;
            if (this.topval < -this.mee.offsetHeight){
                this.topval = this.myparent.offsetHeight;
            }
        }
        requestAnimationFrame((t) => this.anim(t));
    }
}

var adv1 = new parentAdvertising('movdiv', 'parentmovdiv', -2, 60, 0);
requestAnimationFrame((t) => adv1.anim(t));
var adv2 = new parentAdvertising('movdiv2', 'parentmovdiv2', -2, 25, 0  );
requestAnimationFrame((t) => adv2.anim(t));