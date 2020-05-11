#
#  MIEI 19/20 FCT/UNL
#


########
# int match( int a, int b, int c )
#
.text
.globl	match
match:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax # move the variable "a" to %eax
    mov 12(%ebp), %ecx # move the variable "b" to %ecx
    mov 16(%ebp), %edx # move the variable "c" to %edx

    test %eax, %ecx # (a & b) != 0
    jz wrong

    test %eax, %edx # (a & c) == 0
    jnz wrong

    test %ecx, %edx # (b & c) == 0
    jnz wrong

    jmp right

wrong:
    movl $0, %eax # move 0 to %eax, so the function returns false
    jmp end

right:
    movl $1, %eax # move 1 to %eax so the function returns true

end:
    pop %ebp # return %ebp to the original state
    ret
