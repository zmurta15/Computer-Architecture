
/* programa so' para testar a interface do driver
 * para escrever na porta serie
 */
#include <stdio.h>

#include "hw.h"
#include "driver.h"


int main() {
    char *str = "String de teste!\nCorreu bem?\n";

    hwInit("/dev/tty");
    // a string enviada deve aparecer correta no stdout (ecra)
    while ( *str!='\0')
       sendSerial( *str++ );
    waitSerial();
}
