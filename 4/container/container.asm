; container.asm
section .data
    sizeOfMatrix dd 16
    containerDataLen dd 10005
    containerOffset dq 8

section .bss
section .text
    global addContainer
    global sortContainer

addContainer:
    ; INPUT
    ;   Container *containerPtr stored in rdi
    ;   Matrix *matrix stored in rsi

    mov edx, [rdi] ; edx <- container.size

    ; calculating new matrix insertion place in memory
    lea rax, [rdi + 8 + 8 * rdx]; as rax support multiplying of 1, 2, 4, 8 (8 is max), we are doing lea twice
    lea rax, [rax + 8 * rdx]

    ; copying matrix value in 2 steps of 8 bytes
    mov rcx, [rsi]
    mov [rax], rcx
    mov rcx, [rsi + 8]
    mov [rax + 8], rcx

    ; container.size ++
    inc edx
    mov [rdi], edx

    ret

sortContainer:
    ret

