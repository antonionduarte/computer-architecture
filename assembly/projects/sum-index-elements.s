# constants
EXIT = 1
LINUX_SYSCALL = 0x80

# variables
.data
    numbers: .int 35, 2, 5, 17, 10 # array that stores the elements
    LEN = (. - numbers) / 4

    select: .int 2, 0, 4, 2 # array that selects the indexes of the elements to sum in the first array
    LEN2 = (. - select) / 4

    sum: .int 0 # the sum of all the elements of the numbers array, that were selected in the select array

.text
.global _start
_start:
    mov $select, %eax
    mov $LEN2, %ebx
    inc %ebx
    mov (sum), %ecx
cicle:
    dec %ebx
    jz end

    mov (%eax), %edx
    add numbers(,%edx,4), %ecx
    add $4, %eax # sum 4 bytes to the memory in %ebx register to move to the next element in the array
    jmp cicle
end:
    mov %ecx, sum
    mov $0, %ebx
    mov $EXIT, %eax
    int $LINUX_SYSCALL
