.data
    hapesira: .asciiz " "   # Një hapësirë që numrat mos ngjiten

.text
.globl main
main:
    # 1. PËRGATITJA
    addi $16, $0, 0      # Numëruesi fillon nga 0
    addi $17, $0, 5      # Limiti është 5

loop:   # <--- Këtu fillon "rrethi"
    
    # 2. RRIT NUMËRUESIN
    addi $16, $16, 1     # $16 bëhet $16 + 1

    # 3. PRINTO NUMRIN
    addi $2, $0, 1       # Kodi 1 për printim numri
    add $4, $0, $16      # Printo vlerën e numëruesit
    syscall

    # (Opsionale: Printo një hapësirë që të duken bukur)
    addi $2, $0, 4
    la $4, hapesira
    syscall

    # 4. KONTROLLO: A kemi arritur te 5-sa?
    # "Nëse $16 == $17, shko te fundi"
    beq $16, $17, fundi  

    # 5. KËRCE MBRAPSHT
    # Nëse nuk kemi mbaruar akoma, kthehu te 'loop'
    j loop

fundi:
    # Mbyll programin
    addi $2, $0, 10
    syscall