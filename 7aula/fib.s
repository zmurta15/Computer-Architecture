.text
.global fib
fib:
	push %ebp
	mov %esp, %ebp
	mov 8(%ebp), %eax
	cmp $0, %eax
	je fim_fib
	cmp $1, %eax
	je fim_fib
	
	dec %eax #eax = n-1
	push %eax #inicio de fib(n-1)
	call fib
	add $4, %esp #fim do fib(n-1)
	
	push %eax
	mov 8(%ebp), %ecx
	sub $2, %ecx  
	push %ecx    #inicio fib(n-2)
	call fib
	
	add $4, %esp  #fim fib(n-2)
	pop %edx
	add %edx, %eax
	
	

fim_fib:
	pop %ebp
	ret
	