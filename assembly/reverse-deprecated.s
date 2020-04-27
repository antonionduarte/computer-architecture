.data
    msg:	.ascii	"hey dude"
    MSGLEN = (. - msg)
    LASTPOS = (msg + MSGLEN)
    .comm msgInvert, MSGLEN

### do not change this line (your code follows this line)

.text
.global _start
_start:
    mov $LASTPOS, %eax # last position of the msg array (this will effectively store the current position in iteration)
    mov $MSGLEN, %ebx # length of the msg array
    mov $0, %ecx # msgInvert counter

iterate_backwards:
    dec %eax # decrements in one our position in the array
    dec %ebx # decrements the counter that keeps the length of the msg
    jz ebd1

    mov (%eax), %bl # moved this for cmp to only compare one byte
    cmp $0x20, %bl # if it detects the blank character jumps
    jz store_blank_pos

    cmp $msg, %eax # this compares with the case where %eax is in the first position in msg
    jz store_blank_pos
    
    jmp iterate_backwards

store_blank_pos: 
    push %eax # pushes to stack the position of the blank space
    jmp iterate_forward_store

iterate_forward_store:
    inc %ecx
    inc %eax

    mov %eax, %edx # moves current value to a different register
    inc %edx # increments it so we get the value of the next one
    mov (%edx), %al


    mov (%eax), %bl
    mov %bl, msgInvert(,%ecx,1)

    cmp $0x20, %al
    jz pop_and_return
    cmp $0x0A, %al
    jz pop_and_return
    cmp $0x00, %al
    jnz iterate_forward_store

pop_and_return:
    pop %eax # pops back to the old position
    movb $0x20, msgInvert(,%ecx,1)
    jmp iterate_backwards # goes back to iterating backwards in the sentence

continue:

### do not change this line and the lines bellow

# code for debug and testing
EXIT = 1
WRITE = 4
LINUX_SYSCALL = 0x80
	movl	$MSGLEN, %edx
	movl	$msgInvert, %ecx
	movl	$1, %ebx
	movl	$WRITE, %eax	# pedir write ao sistema
	int		$LINUX_SYSCALL	# chama o sistema
	
	movl	$1,	%edx
	movl	$nl, %ecx	
	movl	$1, %ebx
	movl	$WRITE, %eax	# pedir write ao sistema
	int		$LINUX_SYSCALL	# chama o sistema

	movl    $0,%ebx             
	movl    $EXIT,%eax      # pedir o exit ao sistema    
	int     $LINUX_SYSCALL  # chama o sistema
.data
  nl: .ascii  "\n"
