/* 

===== PROG: print_with_linux.c =====================================
=                                                                  =
= this Program only works under linux                              =
= HINTS: if you get this error... system default destination: none =
= lpstat -p     Check current printer                              =
= lpoptions -d currentPrinterName                                  =
= lpstat -d     after that this must show up                       =
= system default destination: currentPrinterName                   =
=                                                                  =
====================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *printer;

    printf("Send print job...\n");

    printer = popen("lp 2>&1", "w");

    if (printer == NULL)
    {
        perror("popen failed");
        return 1;
    }

    fprintf(printer,
        "========================\n"
        "   C PRINT TEST PAGE    \n"
        "========================\n\n"
        "Hello Printer!\n"
        "This is a test from C.\n");

    int status = pclose(printer);

    if (status != 0)
    {
        printf("Print job failed!\n");
        printf("Hint: check 'lpstat -p' and 'lpstat -d'\n");
        return 1;
    }

    printf("Print job sent successfully!\n");

    return 0;
}