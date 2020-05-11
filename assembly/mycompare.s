#
#  MIEI 19/20 FCT/UNL
#


########
# int mycompare( int size, int x[], int y[] )
#
.text
.globl	mycompare
mycompare:
    push %ebp
    mov %esp, %ebp

    mov 16(%ebp), %eax # move memory position of y[0] to %eax
    mov 12(%ebp), %ecx # move memory position of x[0] to %ecx
    movl $0, %edx # move 0 to %edx, this register will act as a counter

    push %ebx # save the current content of %ebx

cicle:
    cmp 8(%ebp), %edx
    jz equal

    mov (%eax), %ebx # move y[0] to %ebx
    cmp %ebx, (%ecx,%edx,4) # compares y[0] with x[0]
    jnz not_equal

    add $4, %eax # sum 4 bits to increment current position of y[]
    inc %edx # increments the counter

    jmp cicle

not_equal:
    mov %edx, %eax # move counter to %eax so the function returns current position
    jmp end

equal:
    movl $-1, %eax # move -1 to %eax so the function returns (-1)
    jmp end

end: 
    pop %ebx # return content of %ebp to the original state
    pop %ebp # return content of %ebx to the original state
    ret
