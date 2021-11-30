; container.asm
section .data
    matrixTag2d dd 1
    matrixTagDiagonal dd 2
    matrixTagLowTriangle dd 3
section .bss
section .text
    global addContainer
    global sortContainer

sortContainer:
    ; INPUT
    ; Container *containerPtr stored in rdi
    push rbp
    mov rbp, rsp

    push rbx
    push rcx
    push rdx

    mov ebx, [rdi]; ebx <- container.size
    mov r15d, [rdi]
    dec r15d
    lea rcx, [rdi + 8]; rcx is container[i]

xor r8d, r8d
sortOuterLoop:
    mov edx, r8d
    inc edx ; edx = rd8d + 1
    lea r12, [rcx + 16] ; r12 is container[j]

    ;calculating avg of container[i]
    push rdi
    mov rdi, rcx
    call average
    movsd xmm3, xmm0
    pop rdi

sortInnerLoop:
    push rdi
    mov rdi, r12
    call average
    movsd xmm4, xmm0
    pop rdi

    comisd xmm3, xmm4
    ja swap
    jmp afterSwap

swap: ;here we need to swap r12 : r12+16 with rcx : rcx+16

    ;making a copy of r12
    mov r13, [r12]
    mov r14, [r12 + 8]

    ;[r12]<-rcx
    mov r9, [rcx]
    mov [r12], r9
    mov r9, [rcx + 8]
    mov [r12 + 8], r9

    ;rcx<-copy of r12(r13, r14)
    mov [rcx], r13
    mov [rcx + 8], r14

    ; recalculation of container[i] average
    push rdi
    mov rdi, rcx
    call average
    movsd xmm3, xmm0
    pop rdi


afterSwap:
    inc edx
    add r12, 16
    cmp edx, ebx
    jl sortInnerLoop

;sortInnerLoopEnd

    inc r8d
    add rcx, 16
    cmp r8d, r15d
    jl sortOuterLoop

;sortOuterLoop end

    pop rcx
    pop rbx
    pop rdx

    leave
    ret


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

average: ;average will be stored in xmm0
    ; INPUT
    ; Matrix *matrix2d stored in rdi
    push rbp
    mov rbp, rsp

    push rbx
    push rcx

    mov ebx, [rdi] ; ebx = matrix.tag

    mov ecx, [matrixTag2d]
    cmp ecx, ebx
    je average2DCall
    jmp check2

average2DCall:
    call average2D
    pop rcx
    pop rbx
    leave
    ret

check2:
    mov ecx, [matrixTagDiagonal]
    cmp ecx, ebx
    je averageDiagonalCall
    jmp check3

averageDiagonalCall:
    call averageDiagonal
    pop rcx
    pop rbx
    leave
    ret

check3:
    mov ecx, [matrixTagLowTriangle]
    cmp ecx, ebx
    je averageLowTriangleCall
    jmp averageEnd

averageLowTriangleCall:
    call averageLowTriangle
    pop rcx
    pop rbx
    leave
    ret

averageEnd:

    pop rcx
    pop rbx
    leave
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