

.data # data section (variables)
  numbers: .int 1, 2, 3, 4
  LEN = (. - numbers)/4
  select: .int 3, 0 # indices of the numbers to be selected
  LEN2 = (. - select)/4
  sum: .int 0 # should contain the sum of the selected numbers

### do not change this line (your code follows this line)

.text
.global _start
_start:
    mov $select, %eax
    mov $LEN2, %ebx
    inc %ebx
    mov (sum), %ecx

cicle:
    dec %ebx
    jz continue

    mov (%eax), %edx
    add numbers(,%edx,4), %ecx
    add $4, %eax # sum 4 bytes to the memory in %ebx register to move to the next element in the array
    jmp cicle

continue:
    mov %ecx, sum

### do not change this line and the lines bellow

# code for debug and testing
EXIT = 1
WRITE = 4
LINUX_SYSCALL = 0x80
    mov sum, %eax
    mov $out+9, %ecx
cont:
    mov $0, %edx
    mov $10, %ebx
    divl %ebx
    add $'0', %dl
    movb %dl, (%ecx)
    dec %ecx
    cmp $0, %eax
    jne cont
    
    mov $11, %edx
    mov $out, %ecx
    mov $1, %ebx
    mov $WRITE, %eax
    int $LINUX_SYSCALL

    movl    $0, %ebx             
    movl    $EXIT, %eax      # pedir o exit ao sistema    
    int     $LINUX_SYSCALL  # chama o sistema
.data
out: .ascii "          \n"
