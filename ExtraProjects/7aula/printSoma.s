.data
format: .ascii "%d\n\0"


.text
.global printSoma

## @arg1: string com digitos (representado um numero)
## @arg2: string com digitos (representado um numero)

printSoma:
	push %ebp
	mov %esp, %ebp
## complete o codigo ##
## objetivo 1: converter o primeiro argumento para um inteiro
	push 8(%ebp)
	call atoi
	add $4, %esp
	push %eax
## complete o codigo ##
## objetivo 2: converter o segundo argumento para um inteiro
	push 12(%ebp)
	call atoi
	add $4, %esp
	pop %ecx #tira o primeiro valor da pilha que era o eax
	
## complete o codigo ##
## objetivo 3: realizar a soma dos dois inteiros
	add %ecx, %eax
## objetivo 4: imprimir o resultado da operação
	push %eax
	push $format
	call printf
	add $8, %esp
## complete o codigo ##
## objetivo 5: garantir que a pilha está no mesmo estado
## em que estava quando printSoma foi invocada
	pop %ebp
	ret
	