# void histograma(int valores[], int size, int histo[])
.text
.globl histograma

histograma:
	push %ebp
	push %ebx
	push %edi
	mov %esp, %ebp
	movl 16(%ebp), %eax # %eax -> valores
	movl 20(%ebp), %ebx # %ebx -> size
	movl 24(%ebp), %ecx # %ecx -> histo
	movl $0, %edx # counter for valores

ciclo:
	cmpl %ebx, %edx
	je end

	movl (%eax, %edx, 4), %edi
	incl (%ecx, %edi, 4)

	incl %edx
	jmp ciclo

end:
	movl %ebp, %esp
	popl %edi
	popl %ebx
	popl %ebp
	ret
