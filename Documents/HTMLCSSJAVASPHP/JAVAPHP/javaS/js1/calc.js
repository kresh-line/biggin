var display=document.getElementById("calcap_display");
var resultValue=0.0;
var storedOperation="=";
// Κρατάω αν πρέπει να ξεκινήσω να γράφω αριθμό από την αρχή
var startFlag= true;
var memoryValue=0.0;

 console.log("resultValue="+resultValue+", storedOperation="+storedOperation);

function addNum(num){
    // Αν έγινε πράξη πριν ξεκίνησε αριθμό από την αρχή
    if (startFlag){
        display.value=num.innerHTML;
        startFlag=false;
    }
    //Αν πατηθεί αριθμός και πριν απλώς πρόσθεσέ τον στο τέλος
    else {
        if(display.value=="0")
            display.value=num.innerHTML;
        else
       display.value= display.value + num.innerHTML;
    }
}

function addPeriod(){
    // Αν δεν έχει πατηθεί πριν (δηλαδή δεν υπάρχει μέσα στο input)
    //τότε πρόσθεσέ το στο τέλος
    if (display.value.indexOf(".")<0) 
        display.value = display.value + ".";
}
function bsp(){
    if (display.value.length<=1)
        display.value="0";
    else{
        display.value= display.value.substring(0, display.value.length-1) ;
    }
    
}

function calc(c){
//alert(c.innerHTML);
 switch(storedOperation) {
    case"+":
    resultValue=resultValue + parseFloat(display.value);
    display.value=resultValue;
    break;

     case"-":
     resultValue=resultValue - parseFloat(display.value);
    display.value=resultValue;
    break;

     case"*":
     resultValue=resultValue * parseFloat(display.value);
    display.value=resultValue;
    break;

     case"/":
     resultValue=resultValue / parseFloat(display.value);
    display.value=resultValue;
    break;

     case"=":
    resultValue=parseFloat(display.value);
    break;

     
    }
    if (c.innerHTML!="=")
    storedOperation=c.innerHTML;

    console.log("resultValue="+resultValue+", storedOperation="+storedOperation);
    startFlag=true;

}
function clearclac(){
resultValue=0.0;
storedOperation="=";
startFlag= true;
display.value="0";
console.log("resultValue="+resultValue+", storedOperation="+storedOperation);
}
function setMem(){
memoryValue=parseFloat(display.value);


}
function getMem(){
display.value=memoryValue;


}