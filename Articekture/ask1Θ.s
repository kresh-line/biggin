.data 
str_prompt: .asciiz "Shkruani nje numer: "
str_min:    .asciiz "Numri me i vogel eshte: "
str_nl:     .asciiz "\n"

.text 
.globl main
.globl loop

main:
    # $16 do te jete Counteri (Numëruesi). 
    # Do lexojme 3 numra total. 1 e lexojme jashte, mbeten 2 per loop.
    addi $16, $0, 2 

    # --- Lexo numrin e pare (fillimi) ---
    addi $2, $0, 4        # Printo "Shkruani nje numer: "
    la   $4, str_prompt
    syscall 

    addi $2, $0, 5        # Lexo numrin
    syscall
    add  $17, $2, $0      # Ruaje numrin e pare tek $17 (Minimumi fillestar)

loop:
    # Kontrollo nese kemi mbaruar numrat (kur $16 behet 0)
    beq  $16, $0, end_loop

    # --- Lexo numrin tjetër ---
    addi $2, $0, 4        # Printo "Shkruani nje numer: "
    la   $4, str_prompt
    syscall

    addi $2, $0, 5        # Lexo numrin
    syscall
    add  $18, $2, $0      # Numri i ri tek $18

    # --- Krahasimi ($18 < $17 ?) ---
    slt  $8, $18, $17     # Nese $18 < $17, atehere $8 behet 1
    beq  $8, $0, skip     # Nese $8 eshte 0, mos e ndrysho minimumin

    add  $17, $18, $0     # Perditeso minimumin ($17 behet sa $18)

skip:
    addi $16, $16, -1     # Zbrit counterin me 1
    j loop                # Kthehu te loop

end_loop:
    # --- Printo rezultatin ---
    addi $2, $0, 4        # Printo tekstin final
    la   $4, str_min
    syscall

    addi $2, $0, 1        # Printo vleren minimale ($17)
    add  $4, $17, $0
    syscall

    addi $2, $0, 4        # Printo rresht te ri
    la   $4, str_nl
    syscall

    # Dil nga programi
    addi $2, $0, 10
    syscall