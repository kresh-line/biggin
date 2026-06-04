const infrm = document.getElementById("insertProductForm");
const pname = document.getElementById("pname");
//Αν υπάρχει αυ΄τη η φόρμα (δηλαδή είμαι στη σελίδα add.php) τότε
//πρόσθεσέ το event submit
if (infrm!==null) {
    infrm.addEventListener("submit", validateInsertForm); 
}

function validateInsertForm(e) {
    let msgstr="";
    
    pname.setCustomValidity("");
    //Πρώτος έλεγχος
    if (pname.value.trim()==="") {
        msgstr = msgstr + "Το όνομα δεν μπορεί να έχει μόνο κενά!<br>";
        pname.setCustomValidity("Όχι μόνο κενά!");
        pname.value="";
        pname.reportValidity();
    }
    if (pname.value.length>100) {
        msgstr = msgstr + "Το όνομα δεν μπορεί να είναι μεγαλύτερο από 100!<br>";
        pname.setCustomValidity("Πολύ μεγάλο όνομα!");
        pname.reportValidity();
    }    
    
    //ακύρωσε το submit
    if (msgstr!=="") {
        document.getElementById("ifem").innerHTML = msgstr;
        e.preventDefault();
    }
    else {
        document.getElementById("ifem").innerHTML = "";
    }
}

//Αν επιστρέψει true θα γίνει το submit αλλιώς 
//δεν θα γίνει το submit
function validateDeleteForm() {
  
    let answer = confirm("Είστε σίγουρος ότι θέλετε να διαγράψετε το προϊόν;");
  
    if (answer==true)
        return true;
    else
        return false;
}

//Αν επιστρέψει true θα γίνει το submit αλλιώς 
//δεν θα γίνει το submit
function validateUpdateForm(fnum) {
    let errormsg = "";
    let frm = document.getElementById("updateForm"+fnum);
    
    let prodname = frm.elements['pname'].value;
    let prodprice = frm.elements['pprice'].value;
    
    let num=1;
    //Έλεγξε αν το όνομα του προϊόντος είναι κενό, αφού πρώτα αφαιρέσεις
    //τα κενά μπροστά και πίσω με τη μέθοδο trim()
    if (prodname.trim()=="") { 
        errormsg = errormsg + num +". Το όνομα του προϊόντος δεν μπορεί να είναι κενό!\n";
        num++;
    }    
    //Έλεγξε αν η τιμή του προιόντος είναι μικρότερη ή ίση του 0
    if (prodprice<=0) { 
        errormsg = errormsg + num + ". Η τιμή του προϊόντος πρέπει να είναι μεγαλύτερη του μηδενός!\n";
        num++;
    }
    //Ελέγχω όσα πεδία θέλω ......
    
    if (errormsg=="")
        return true;
    else {
        if (num<=2)
            alert("Δεν μπορεί να γίνει η ενημέρωση γιατί υπάρχει το εξής λάθος:\n"+errormsg);
        else
            alert("Δεν μπορεί να γίνει η ενημέρωση γιατί υπάρχουν τα εξής λάθη:\n"+errormsg);
        return false;
    }
}
