.data
str_n: .asciiz "n= "
str_s:  .asciiz "*"
str_nl: .asciiz "\n"
.text
.globl main
.globl loop
main:
addi $2, $0, 4
la $4, str_n
syscall 
addi $2, $0, 5       
syscall                    
add $16, $2, $0
addi $17, $0, 0
 #n=$16 $17=i $18=y for(i=0; i<N; i++)  for(y=0; y<=i; y++)
 loop:
 addi $2, $0, 4
la $4, str_s
syscall 
addi $2, $0, 4
la $4, str_nl
syscall
 addi $17, $17, 1
 beq $16, $17, exit
 j loop
 exit:


