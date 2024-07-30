#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "bit_manip.h"
#include "bit_manip_algorithms.h"




//*****************************************************************************
// Function: main
//
// Description: 
//
// Parameters: 
//
// Return: 
//
//*****************************************************************************
int main(int argc, char *argv[])
{
    uint32_t func = FIRST_ALGO_FUNC;
    uint32_t rval = 0;

    if (2 <= argc) {
        func = (strtol(argv[1], NULL, 10));
    }

    do {
          rval = ptr_func[func]();
          if (0 == rval) {
              func += 1;
              continue;
          }
          func = rval - 0x30;

    } while((RUN_ALL <= func) && (LAST_ALGO_FUNC >= func));
}


