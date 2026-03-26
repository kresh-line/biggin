.text
.globl main
main:
    # 1. Lexo numrin e parë
    addi $2, $0, 5      # Përgatit kodin për lexim
    syscall             # Ekzekuto leximin
    add $16, $0, $2     # Ruaj numrin e parë te $16

    # 2. Lexo numrin e dytë
    addi $2, $0, 5      # Përgatit kodin për lexim
    syscall             # Ekzekuto leximin
    add $17, $0, $2     # Ruaj numrin e dytë te $17

    # 3. Mbledhja
    add $18, $16, $17   # $18 = $16 + $17

    # 4. Printo rezultatin
    addi $2, $0, 1      # Përgatit kodin për printim numri
    add $4, $0, $18     # Vendos vlerën që do printohet te $4
    syscall             # Ekzekuto printimin

    # 5. Mbyll programin
    addi $2, $0, 10     
    syscall