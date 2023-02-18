 
.data
	num:	.int 3500
	res:    .ds.b 32, '0' # space for the result: fill 32 bytes with zero chars
	nl:     .ascii "\n"

### do not change this line (your code follows this line)


.text
.global _start 
_start:		# TODO:
	movl (num), %eax
	#movl $res, %ecx
	movl $0, %edx
	
loop1:
	cmp $32, %edx
	je end
	shl $1, %eax
	jnc sub1
	jc sub2
	
sub1:
	inc %edx
	jmp loop1
sub2:
	movb $'1', res(%edx)
	inc %edx
	jmp loop1

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

