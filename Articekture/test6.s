.data
str_n: .asciiz "num = "
str_s: .asciiz "sum="
str_nl: .asciiz "\n"

.text
.globl main


main:
#################################
      
	  addi $2, $0, 4
      la $4, str_n
    syscall

     addi $2, $0, 5
    syscall
add $16,$2, $0
###################################################

addi $2, $0, 4
      la $4, str_n
    syscall

     addi $2, $0, 5
    syscall
add $17,$2, $0

############################################

addi $2, $0, 4
      la $4, str_n
    syscall

     addi $2, $0, 5
    syscall
add $18,$2, $0
################################################
 add $2, $0, 4
 la $4, str_s
 syscall
 addi $2, $0, 1
 add $4, $16, $0
 syscall



