// αν επιστρέφει false, δεν θα υποβληθεί η φόρμα αλιωσ θα ειναι true, οπότε θα υποβληθεί
function validateForm() {
    return false;}

var infrm = document.getElementById('insertProductForm');
//αν υπαρχι η φορμα με id insertProductForm, προσθεσε event listener για το submit, και καλεσε την validateInsertForm
if (infrm!==null)
    infrm.addEventListener('submit', validateInsertForm);

function validateInsertForm(e) {
    let msgstr = "";
   if (infrm.elements['pname'].value.trim() ==="") {
       msgstr = msgstr + "Το όνομα του προϊόντος δεν μπορεί να είναι κενό.\n";
    
   }    
    if (msgstr!=="") {
        document.getElementById('ifem').innerHTML = msgstr;
        e.preventDefault();
    
    }
    else
        return true;
}
function validateDeleteForm() {

    let answer = confirm("Είστε σίγουροι ότι θέλετε να διαγράψετε αυτό το προϊόν;");
    if (answer==true) 
        return true;
     else 

        return false;
}


function validateUpdateForm(pid) {
    let errormsg = "";
    let frm = document.getElementById('updateForm' + pid);
    let prodname = frm.elements['pname'].value;
    let prodprice = frm.elements['pprice'].value;

    let num=1;
    // ελεγχος για το ονομα, αν ειναι κενό, προσθετω στο errormsg, και αυξάνω το num για να ξεκινάει από 1 και να μετράει τα λάθη
    if (prodname.trim() == "") {
        errormsg = errormsg + num + ". Το όνομα του προϊόντος δεν μπορεί να είναι κενό.\n";
        num++;
    }
    if (prodprice.trim() == "") {
        errormsg = errormsg + num + ". Η τιμή του προϊόντος δεν μπορεί να είναι κενή.\n";
        num++;
    } else if (prodprice.trim() <= 0) {
        errormsg = errormsg + num + ". Η τιμή του προϊόντος πρέπει να είναι θετικός αριθμός.\n";
        num++;
    }
    // ελεχνο οσα θελω και αν βρω λαθη, τα προσθετω στο errormsg, και στο τελος αν δεν ειναι κενό, τα εμφανιζω ολα μαζι με alert
    if (errormsg == "")
        return true;
    else {
        if (num <= 2)
            alert("Υπάρχει το εξής λάθος:\n" + errormsg);
        else
            alert("δεν μπορι να υποβληθεί η φόρμα για τους εξής λόγους:\n" + errormsg);
        return false;
    }

        
    }


 
    
    
