var mydiv = document.getElementById("contentdiv");
mydiv.addEventListener("click", takeOldValue);

var listelem = document.getElementById("listelem");
var oldlistelem = document.getElementById("oldlistelem");
//document.addEventListener("load", printArrayList);
//pare to span me id listnum kai vale to megethos tou pinaka
var errorspan = document.getElementById("errorspan");


var arr = ["black", "orange", "pink", "blue", "red",];

function printArrayList() {
    let i;
    let htmlcont = "<ul>";
    
    for (i=0;i<arr.length;++i) {
        htmlcont = htmlcont + "<li><span>"+arr[i]+"</span></li>";
    }
    htmlcont = htmlcont + "</ul>";
    mydiv.innerHTML = htmlcont;
    document.getElementById("listnum").innerHTML = arr.length;
}

function addToArray() {
    if (listelem.value!=null && listelem.value.trim()!="") {
        let index = findInArray(listelem.value.trim());
        if (index==-1) {
            arr[arr.length] = listelem.value.trim();
            printArrayList();
        }
        else
            errorspan.innerHTML = "Η τιμή υπάρχει ήδη στη λίστα";
            
    }
    else
        errorspan.innerHTML = "Συμπληρώστε την τιμή του πεδίου!";
        //alert("Συμπληρώστε την τιμή του πεδίου!");
}

/*
 * Συνάρτηση που παίρνει ως παράμετρο ένα string και το αναζητά στον πίνακα
 * Αν το βρει επιστρέφει τη θέση του, αλλιώς επιστρέφει -1
 */
function findInArray(elem) {
    let i;
    for (i=0;i<arr.length;++i) {
        if (arr[i]==elem)
            return i;
    }

    //δεν το βρέθηκε επιστρέφει -1
    return -1;
}
// αλλαξε το στοιχείο που έχει την τιμή που βρίσκεται στο oldlistelem με την τιμή που βρίσκεται στο listelem

function changeInArray() {
    if ((listelem.value!=null && listelem.value.trim()!="") && (oldlistelem.value!=null && oldlistelem.value.trim()!="")) {
        //alert("Αλλαγή");
        //Έλεγξε αν πατήθηκε <li>
        let index = findInArray(oldlistelem.value);
        let newIndex = findInArray(listelem.value.trim());
        if (newIndex != -1) {
            errorspan.innerHTML = "Η τιμή υπάρχει ήδη στη λίστα";
            return;
        }
        // αλλαξε το στοιχείο που έχει την τιμή που βρίσκεται στο oldlistelem με την τιμή που βρίσκεται στο listelem
        arr[index] = listelem.value;
        printArrayList();
    errorspan.innerHTML = " Η αλλαγή έγινε επιτυχώς!";

    }
    else
        errorspan.innerHTML = "Συμπληρώστε και τα δύο πεδία!";
}


function takeOldValue(e) {
    //Έλεγξε αν πατήθηκε <li>
    if (e.target.nodeName=="SPAN") {
        oldlistelem.value = e.target.innerHTML;
    }
}