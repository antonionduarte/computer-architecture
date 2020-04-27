# constants
EXIT = 1
LINUX_SYSCALL = 0x80

# variables
.data
    msg: .ascii "hey jude"
    MSGLEN = (. - msg)

    .comm msgInvert, MSGLEN
    msgInvertCounter: .int 0

# code
.text
.global _start
_start:
    mov $msg, %eax # save memory location of first position of the msg in the %eax
    push $msg # do the same as before but put it in stack
    mov $MSGLEN, %ebx # save the length of the message in %ebx register
    mov $2, %ecx # moves 0 %ecx, register that is going to store the counter of blank spaces
    mov msgInvert, %edx

find_blanks:
    dec %ebx
    jz next_blank

    cmp $0x20, (%eax) # compare the char of the msg array with 0x20, which is blank space
    jz store_blank
    inc %eax

    jmp find_blanks

store_blank:
    push %eax # saves the position of the blank space to stack
    inc %ecx # increments %ecx, register that will save the amount of blank spaces
    jmp find_blanks  

next_blank:
    sub $1, %ecx # decrements the counter of blank spaces
    jbe end # jumps to the end when there are no more words to move

    mov msgInvertCounter, %ebx # places counter of msgInvert in %ebx register
    pop %eax # pops position of blank space
    jmp store_word # calls sub-routine that is going to store word in msgInvert

store_word:
    inc %eax
    inc %ebx

    mov (%eax), %edx
    mov %edx, msgInvert(,%ebx,1) # moves char to msgInvert

    mov %ebx, msgInvertCounter
    cmp $0x20, (%eax) # detect if the char is the blank space
    jz next_blank
    cmp $0x00, (%eax) # detect if the char is the null char change
    jnz store_word

    jmp next_blank

end:
    mov $0, %ebx
    mov $EXIT, %eax
    int $LINUX_SYSCALL
