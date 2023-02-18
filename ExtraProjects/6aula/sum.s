

# pseudoconstantes
EXIT = 1
WRITE = 4
LINUX_SYSCALL = 0x80

.data          # secção de dados (variáveis)
var1:  .int 25
var2:  .int 3
result:  .int 0

.text           # secção de código
.global _start   # exportar o simbolo _start (inicio do programa)
_start:
	mov		(var1), %eax
	add		(var2), %eax
	mov		%eax, result

	movl    $0,%ebx             
	movl    $EXIT,%eax      # pedir o exit ao sistema    
	int     $LINUX_SYSCALL  # chama o sistema

