; container.asm
section .data
section .bss
section .text
    global addContainer
    global sortContainer

addContainer:
    ; INPUT
    ;   Container *containerPtr stored in rdi
    ;   Matrix *matrix stored in rsi
    push rbp
    mov rbp, rsp

    push rax
    push rcx
    push rdx

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

    pop rdx
    pop rcx
    pop rax

    leave
    ret

sortContainer:
    ret

average2D: ; average will be stored in xmm0
    ; INPUT
    ; Matrix *matrix2d stored in rdi
    push rbp
    mov rbp, rsp

    push rbx
    push rdx
    push r12

    xorps xmm1, xmm1
    mov ebx, [rdi + 4] ; ebx = matrix.size
    mov rdx, [rdi + 8] ; rdx = matrix.ptr
    mov rdx, [rdx] ; rdx = matrix.ptr.data*

    xor ecx, ecx

loopOuter:
    xor eax, eax
    mov r12, [rdx]

loopInner:
    addsd xmm1, [r12]
    add r12, 8
    inc eax
    cmp eax, ebx
    jl loopInner

;loopInner end
    add rdx, 8
    inc ecx
    cmp ecx, ebx
    jl loopOuter
;loopOuter end

    cvtsi2sd xmm2, ebx
    divsd xmm1, xmm2
    divsd xmm1, xmm2
    movsd xmm0, xmm1

    pop r12
    pop rdx
    pop rbx

    leave
    ret

averageDiagonal: ; average will be stored in xmm0
    ; INPUT
    ; Matrix *matrix2d stored in rdi
    push rbp
    mov rbp, rsp

    push rbx
    push rdx

    xorps xmm1, xmm1
    mov ebx, [rdi + 4] ; ebx = matrix.size
    mov rdx, [rdi + 8] ; rdx = matrix.ptr
    mov rdx, [rdx] ; rdx = matrix.ptr.data

    xor eax, eax

loop1:
    addsd xmm1, [rdx]
    add rdx, 8
    inc eax
    cmp eax, ebx
    jl loop1
    ;loop 1 end

    cvtsi2sd xmm2, ebx
    divsd xmm1, xmm2
    divsd xmm1, xmm2
    movsd xmm0, xmm1

    pop rdx
    pop rbx
    leave
    ret

averageLowTriangle: ; average will be stored in xmm0
    ; INPUT
    ; Matrix *matrix2d stored in rdi
    push rbp
    mov rbp, rsp

    push rbx
    push rdx
    push rcx

    xorps xmm1, xmm1
    mov ebx, [rdi + 4] ; ebx = matrix.size
    mov rdx, [rdi + 8] ; rdx = matrix.ptr
    mov rdx, [rdx] ; rdx = matrix.ptr.data

    mov eax, ebx
    inc ebx
    push rdx
    mul ebx ; rdx:rax = eax * ebx
    pop rdx
    dec ebx
    shr eax, 1 ; now eax = (matrix.size * (matrix.size + 1)) / 2

    xor ecx, ecx

loop2:
    addsd xmm1, [rdx]
    add rdx, 8
    inc ecx
    cmp ecx, eax
    jl loop2
    ;loop 2 end

    cvtsi2sd xmm2, ebx
    divsd xmm1, xmm2
    divsd xmm1, xmm2
    movsd xmm0, xmm1

    pop rcx
    pop rdx
    pop rbx
    leave
    ret