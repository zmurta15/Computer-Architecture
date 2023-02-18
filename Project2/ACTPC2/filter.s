 
.data
	str:	.ascii "11111\0"  # nul char terminated string (like C string)
	remove:	.byte	'1'     #char to remove from str
	
	res:     .ds.b 1024, 0   # space for the result: fill 1024 bytes with zero
	ressize: .int 0	     # size of the result string

### do not change this line (your code follows this line)


.text
.global _start 
_start:		# TODO:
	movl $str, %eax
	movb remove, %bl
	movl ressize, %edx
	movl $res, %ecx
	
loop1: 
	movb (%eax), %bh
	cmp $0, %bh
	je fim
	cmp %bl, %bh 
	je loopigual
	jne loopdiferen
	
loopigual:
	addl $1, %eax
	jmp loop1
	
loopdiferen:
	inc %edx
	movb %bh, (%ecx)
	addl $1, %eax
	addl $1, %ecx
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


