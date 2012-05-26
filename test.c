#include "cliopts.h"
#include <stdlib.h>
#include <stdio.h>

int An_Integer = 0;
unsigned int An_Unsigned = 0;
char *A_String = NULL;
int A_Boolean = 0;
int HexVal = 0x0;

cliopts_entry entries[] = {
        {'i', "int", CLIOPTS_ARGT_INT, &An_Integer, "A simple integer" },
        {'u', "unsigned", CLIOPTS_ARGT_UINT, &An_Unsigned, "An unsigned value"},
        {'s', "string", CLIOPTS_ARGT_STRING, &A_String, "a string" },
        {'H', "hex", CLIOPTS_ARGT_HEX, &HexVal, "Hexadecimal Value" },
        {'v', "verbose", CLIOPTS_ARGT_NONE, &A_Boolean, "a boolean" },
        { 0 }
};


int main(int argc, char **argv)
{
    int last_opt;
    cliopts_entry *cur;

    cliopts_parse_options(entries, argc, argv, &last_opt, NULL);

    /* Simple */

    if (A_String) {
        printf("Have string: %s\n", A_String);
    }
    if (An_Integer) {
        printf("Have integer %d\n", An_Integer);
    }
    if (An_Unsigned) {
        printf("Have unsigned: %u\n", An_Unsigned);
    }
    if (HexVal) {
        printf("Have hex: %x\n", HexVal);
    }
    /* If you feel masochistic, you can use a loop. This is necessary
     * if you want to know whether an option was specified on the command
     * line, or how many times it was specified
     */

    for (cur = entries; cur->dest; cur++) {
        printf("Option %s found %d times\n", cur->klong, cur->found);
    }

    printf("Boolean value: %d\n", A_Boolean);


    return 0;

}
