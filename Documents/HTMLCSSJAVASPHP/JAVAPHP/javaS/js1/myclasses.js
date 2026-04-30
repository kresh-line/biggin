class viewportAdvertising {

    constructor(id, step,topval, leftval, widthval) {
        this.id = id;
        this.step = step;
        this.gmdiv = document.getElementById(id);
        this.val = 0;
        this.widthval = widthval;
        this.gmdiv.style.left = leftval + "px";
        this.gmdiv.style.top = topval + "px";
        this.setCSS();

    }
    setCSS(){
        this.gmdiv.style.position = "fixed";
        //this.gmdiv.style.zIndex = 100;
        this.gmdiv.style.width = this.widthval + "px";
        //this.gmdiv.style.backgroundColor = "white";
    }
    animleft() {
        this.gmdiv.style.left = this.val + "px";
        this.val += this.step;

        if (this.val > window.innerWidth - this.gmdiv.offsetWidth || this.val < 0) {
            this.step = -this.step;
        }
        requestAnimationFrame(() => this.animleft());
    }
    animtop() {
        this.gmdiv.style.top = this.val + "px";
        this.val += this.step;

        if (this.val > window.innerHeight - this.gmdiv.offsetHeight || this.val < 0) {
            this.step = -this.step;
        }
        requestAnimationFrame(() => this.animtop());
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
        let width = ev.target.offsetWidth;
        ev.target.style.width = (width + 20) + "px";
        if (ev.target.getAttribute("data-MGS") != null)
            alert(ev.target.getAttribute("data-MGS"));
    }

}
/*var d1 = new viewportAdvertising('globalmovdiv', 3, 0, 110, 400);
requestAnimationFrame(() => d1.animleft());

var d2 = new viewportAdvertising('globalmovdiv2', 3, 200, 300, 400);
requestAnimationFrame(() => d2.animleft());
*/
var cc = new cleverContainer('.cleverp');
