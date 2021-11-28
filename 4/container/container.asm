; container.asm
SECTION .DATA
    msg db      'test', 10, 0
    len equ     $ - msg - 1
section .bss
section .text
    global addContainer
    global sortContainer

addContainer:
    mov eax, 4            ; 'write' system call = 4
    mov ebx, 1            ; file descriptor 1 = STDOUT
    mov ecx, msg        ; string to write
    mov edx, len     ; length of string to write
    int 80h              ; call the kernel
    ret

sortContainer:
    ret

