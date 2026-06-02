function drag(e){
    // oriste to id tou element pou thelo na metakinisomiso
    e.dataTransfer.setData("text", e.target.id);
}
function allowDrop(e){
    e.preventDefault();
}
function drop(e){
    e.preventDefault();
    // pare ta dedomena pou exo orisei sto drag kai vale ta mesa sto element pou thelo na metakinisomiso
    let d = e.dataTransfer.getData("text");
    e.target.appendChild(document.getElementById(d));
}

function drag2(e){
    e.dataTransfer.setData("text", e.target.id);
}
function allowDrop2(e){
    e.preventDefault();
}
function drop2(e){
    e.preventDefault();
    let d = e.dataTransfer.getData("text");
    e.target.appendChild(document.getElementById(d));
    /*if (target.tagName === "IMG") target = target.parentElement;
    target.appendChild(document.getElementById(d));*/
}