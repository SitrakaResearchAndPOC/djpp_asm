section .data
    ; Définition des données pour le débogage et l'affichage
    label db "Example Label", 0  ; Chaîne de caractères pour dump_mem

section .text
    global _start

_start:
    ; Exemple d'utilisation explicite des fonctions sans macros

    ; 1. Appeler sub_dump_regs
    ; Remplace `dump_regs` macro
    push    dword 0x12345678      ; Exemple de valeur à afficher
    call    sub_dump_regs
    add     esp, 4               ; Nettoyer la pile après le push

    ; 2. Appeler sub_dump_mem
    ; Remplace `dump_mem` macro
    push    dword 16             ; Nombre de paragraphes à afficher
    push    dword 0x1000         ; Adresse de départ
    push    dword label          ; Pointeur vers l'étiquette ou chaîne
    call    sub_dump_mem
    add     esp, 12              ; Nettoyer la pile après 3 pushes

    ; 3. Appeler sub_dump_math
    ; Remplace `dump_math` macro
    push    dword 0x42           ; Exemple de paramètre à afficher
    call    sub_dump_math
    add     esp, 4               ; Nettoyer la pile après le push

    ; 4. Appeler sub_dump_stack
    ; Remplace `dump_stack` macro
    push    dword 0xDEAD         ; Exemple de 3e paramètre
    push    dword 0xBEEF         ; Exemple de 2e paramètre
    push    dword 0xFACE         ; Exemple de 1er paramètre
    call    sub_dump_stack
    add     esp, 12              ; Nettoyer la pile après 3 pushes

    ; Sortie propre du programme
    mov     eax, 1               ; Code système pour exit()
    xor     ebx, ebx             ; Code de sortie 0
    int     0x80                 ; Appeler le noyau pour quitter
