.data # init. data memory with the strings needed:
str_n: .asciiz "n = "
str_s: .asciiz "      s = "
str_nl: .asciiz "\n"

.text 
.globl main

.globl loop

main:
addi $2,$0, 4
la   $4, str_n
syscall 

addi $2, $0, 5
syscall
add  $16, $2, $0

add $17, $0, $0
addi $18, $0, 1

loop:
 add $17, $17, $18
 addi $18, $18, 1
 bne $18, $16, loop
 
 addi  $2, $0, 4
 la $4, str_s
 syscall
 addi $2, $0, 1
 add $4, $17, $0
 syscall
 addi $2, $0, 4
 la $4, str_nl
 syscall
 
 j main 