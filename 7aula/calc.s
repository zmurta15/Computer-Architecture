/* calc.s
* for Linux (32bits)
*/
.text
.global calc
calc:
 push %ebp
 mov %esp, %ebp
 mov 8(%ebp), %eax # get argument (EBP+8)
 add $1,%eax
 pop %ebp
 ret
 