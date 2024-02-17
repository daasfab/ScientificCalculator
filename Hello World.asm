section .data
    helloMsg db 'Hello, World!', 0   ; Define a null-terminated string

section .text
    global _start                    ; Entry point for the program

_start:
    ; Write the string to stdout
    mov     eax, 4                  ; syscall number for sys_write
    mov     ebx, 1                  ; file descriptor 1 (stdout)
    mov     ecx, helloMsg           ; pointer to the message
    mov     edx, 13                 ; length of the message
    int     0x80                    ; call the kernel

    ; Exit the program
    mov     eax, 1                  ; syscall number for sys_exit
    xor     ebx, ebx                ; return code 0
    int     0x80                    ; call the kernel