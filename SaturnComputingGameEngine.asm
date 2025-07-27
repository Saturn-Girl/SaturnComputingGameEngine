; SaturnComputingGameEngine.asm

[BITS 64]

section .data
    data dq 24
    bit dq 32

section .text
    global _start
    global _add

_start:
    mov rdi, 1
    mov rdi, [data]
    mov rsi, [bit]

    mov rax, 16
    add rax, rsi

    push rax
    push rdi
    call _add
_add:
    mov rbx, 24
    mov rcx, 16

    push rbx
    push rcx

    add rbx,rcx
