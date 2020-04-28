# pseudoconstantes
EXIT = 1
WRITE = 4
LINUX_SYSCALL = 0x80

.data          # secção de dados (variáveis)
var1:   .int 35 # primeiro valor a somar
var2:   .int 10 # segundo valor a somar
result: .int 0 # variável onde deve ficar o resultado

.text           # secção de código
.global _start   # exportar o simbolo _start (inicio do programa)
_start:
    mov     var1, %eax # soma ambas as variáveis
    mov     var2, %ebx
    add     %eax, %ebx
    mov     %ebx, result

    mov     $0, %ecx # sai do programa
    mov     $EXIT, %eax
    int     $LINUX_SYSCALL # chama o sistema
