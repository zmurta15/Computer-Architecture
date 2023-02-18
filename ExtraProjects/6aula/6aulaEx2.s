

.data
	vetor:	.int -1, 5, 1, 1, 4
	len = (. - vetor)/4 #1020-1000 = 20 /4= 5 posicoes do vetor
	soma:  .int 0
	
.text
.global _start
_start:
	mov $vetor, %edx
	mov $len, %ebx
	mov soma , %eax
	mov $0, %ecx //tipo counter
inicio_for:
		cmp %ecx, %ebx
		jz fim_for
		add (%edx), %eax
		add $4, %edx
		inc %ecx
		jmp inicio_for
	
fim_for:
	movl    $0,%ebx             
	movl    $EXIT,%eax      # pedir o exit ao sistema    
	int     $LINUX_SYSCALL  # chama o sistema