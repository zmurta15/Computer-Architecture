 
.data
	str:	.ascii "11111\0"  # nul char terminated string (like C string)
	remove:	.byte	'1'     #char to remove from str
	
	res:     .ds.b 1024, 0   # space for the result: fill 1024 bytes with zero
	ressize: .int 0	     # size of the result string

### do not change this line (your code follows this line)


.text
.global _start 
_start:		# TODO:
	movl $str, %eax #move o que esta no str para %eax
	movb remove, %bl #move o char em remove para %bl
	movl ressize, %edx #move o inteiro que esta inicialmente a 0 para %edx
	movl $res, %ecx #move o res, que sera a nova string, para %ecx
	
loop1: 
	movb (%eax), %bh #move o char guardado em %eax para %bh
	cmp $0, %bh #compara, se for igual a 0 (\0) entao vai para o fim
	je fim 
	cmp %bl, %bh #compara o char a remover com o char guardado de str
	je loopigual #se for igual vai para o loopigual
	jne loopdiferen #se for diferente vai para o loopdiferen
	
loopigual:
	addl $1, %eax #avanca para o char a seguir
	jmp loop1 #volta para o loop1
	
loopdiferen:
	inc %edx #incrementa o %edx que guarda o tamanho do res
	movb %bh, (%ecx) #move o byte guardado da string para o res
	addl $1, %eax #avanca para o seguinte char da str
	addl $1, %ecx #avanca para o seguint char do res
	jmp loop1
	
fim:
	addl %edx,ressize
		
	
### do not change this line and the lines bellow

EXIT = 1
WRITE = 4
LINUX_SYSCALL = 0x80
	movl ressize, %edx
	movl $res, %ecx
	movl $1, %ebx
	movl $WRITE, %eax
	int $LINUX_SYSCALL		# write 'res'

 	movl $0,%ebx
 	movl $EXIT,%eax
 	int  $LINUX_SYSCALL		# exit


