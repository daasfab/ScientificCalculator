section .data
    helloWorldMsg db 'Hello, World!', 0  

section .text
    global _start                    ; Entry point for the program

_start:
    ; Write the string to stdout
    mov     eax, 4                 
    mov     ebx, 1                  
    mov     ecx, helloWorldMsg         
    mov     edx, 13                 
    int     0x80                   

    ; Exit the program
    mov     eax, 1                 
    xor     ebx, ebx                
    int     0x80                  
