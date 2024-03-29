.data
    msg:	.ascii  "March was an awkward month"
    MSGLEN = (. - msg)
    .comm msgInvert, MSGLEN

### do not change this line (your code follows this line)

LASTPOS = (msg + MSGLEN)

.text
.global _start
_start:
    mov $LASTPOS, %eax # last position of the msg array (this will effectively store the current position in iteration)
    mov $0, %ecx # msgInvert counter

backwards:
    cmp $msg, %eax # compare if it is the first position of the array
    jz end

    dec %eax # decrement to move back on the msg array
    jz end

    cmpb $0x20, (%eax) # compare character that is in current memory position with blank space character
    jz call_forward
    cmp $msg, %eax # compares if it is the first character in the array
    jnz backwards

final_call_forward: # this call_forward is only used in last word and does not increment the %edx register before it is called
    mov %eax, %edx # store the current position to move forward from
    call forward_store # calls the sub-routine that will iterate forward and save the word to msgInvert
    jmp backwards

call_forward:
    mov %eax, %edx # store current position to move forward from
    inc %edx # increments %edx so the blank space is not written automatically
    call forward_store # call the sub-routine that will iterate forward and save the word to msgInvert
    jmp backwards

forward_store:
    mov (%edx), %bl
    mov %bl, msgInvert(,%ecx,1)
    
    inc %ecx # increment the counter of msgInvert
    inc %edx # increment the register where the memory position of current element is stored

    cmpb $0x00, (%edx) # compares current element with "\0"
    jz return
    cmpb $0x0A, (%edx) # compares current element with "\n"
    jz return
    cmpb $0x20, (%edx) # compares current element with blank space
    jnz forward_store

return:
    movb $0x20, msgInvert(,%ecx,1) # writes blank space
    inc %ecx # increments counter of msgInvert
    ret

end:

### do not change this line and the lines bellow

# code for debug and testing
EXIT = 1
WRITE = 4
LINUX_SYSCALL = 0x80
	movl	$MSGLEN, %edx
	movl	$msgInvert, %ecx
	movl	$1, %ebx
	movl	$WRITE, %eax # asks write to the system
	int		$LINUX_SYSCALL # calls the system
	
	movl	$1,	%edx
	movl	$nl, %ecx	
	movl	$1, %ebx
	movl	$WRITE, %eax # asks write to the system
	int		$LINUX_SYSCALL # calls the system

	movl  $0,%ebx             
	movl  $EXIT,%eax # asks exist to the system 
	int   $LINUX_SYSCALL # calls the system
.data
  nl: .ascii  "\n"
