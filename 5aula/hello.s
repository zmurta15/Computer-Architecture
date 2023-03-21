

# pseudoconstantes
EXIT = 1
WRITE = 4
LINUX_SYSCALL = 0x80

.data          # secção de dados (variáveis)

msg:	.ascii	"AC!\n"   # um vetor de caracteres
msglen = (. - msg)

.text           # secção de código
.global _start   # exportar o simbolo _start (inicio do programa)
_start:
	movl	$msglen, %edx
	movl	$msg, %ecx
	movl	$1, %ebx
	movl	$WRITE, %eax	# pedir write ao sistema
	int	$LINUX_SYSCALL	# chama o sistema

	movl    $0,%ebx             
	movl    $EXIT,%eax      # pedir o exit ao sistema    
	int     $LINUX_SYSCALL  # chama o sistema

