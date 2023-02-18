 
.data
	num:	.int 3500
	res:    .ds.b 32, '0' # space for the result: fill 32 bytes with zero chars
	nl:     .ascii "\n"

### do not change this line (your code follows this line)


.text
.global _start 
_start:		# TODO:
	movl (num), %eax #move o numero 3500 em binario para %eax
	movl $0, %edx #move o valor 0 para %edx, funciona como contador
	
loop1:
	cmp $32, %edx #se o contador for 32 vai para o fim, ou seja, se ja se tiver dado shift left 32 vezes
	je end #salta para o fim
	shl $1, %eax #shift left 1 vez ao numero 3500 em binario, "adiciona zeros a direita, saindo carry 0 ou 1
	jnc sub1 #se o carry for 0 vai para a subrotina sub1
	jc sub2 #se o carry for 1 vai para a subrotina sub2
	
sub1:
	inc %edx #aumenta 1 ao contador
	jmp loop1 #retorna ao loop1
sub2:
	movb $'1', res(%edx)  #mete o ascii 1 na posicao edx, ou seja vai procurar no res a posicao "contador" e meter 1
	inc %edx #aumena 1 ao contador
	jmp loop1 #volta ao loop1

end:
	


### do not change this line and the lines bellow

EXIT = 1
WRITE = 4
LINUX_SYSCALL = 0x80
	movl $33, %edx
	movl $res, %ecx
	movl $1, %ebx
	movl $WRITE, %eax
	int $LINUX_SYSCALL	# write 'res'

 	movl $0,%ebx
 	movl $EXIT,%eax
 	int  $LINUX_SYSCALL	# exit

