.text
.globl main 
main:
addi $16 , $0, 10
addi $17 , $0, 64
addi $18 , $16, 17
addi $18 , $18, 18
addi $18 , $17, 18
addi $17 , $17, -1
sub $17 , $17, $16
j main 

