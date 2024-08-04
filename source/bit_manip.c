#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "bit_manip.h"
#include "bit_manip_algorithms.h"




//*****************************************************************************
// Function: main
//
// Description: Call various bit manipulation exercises by function index.
//
// Parameters: Standard executable parameters, argv[1] contains a function
//             index, if valid.
//
// Return: Status code, hard coded to return 0 (SUCCESS)
//
//*****************************************************************************
int main(int argc, char *argv[])
{
    uint32_t func_idx = FIRST_ALGO_FUNC;
    uint32_t rval = 0;

    if (2 <= argc) {
        func_idx = (strtol(argv[1], NULL, 10));

        // check for input in range.
        if ((RUN_ALL >= func_idx) || (LAST_ALGO_FUNC < func_idx)) {
            func_idx = FIRST_ALGO_FUNC;
        }
    }

    do {
          // call the indexed function, which returns the next function index.
          rval = ptr_func[func_idx]();

          // check special cases that simply increment the function index.
          if ((0 == rval) || (10 == rval)) {
              func_idx += 1;
              continue;
          }

          // adjust ascii number, the while condition will validate.
          func_idx = rval - 0x30;

    // use the function index if valid.
    } while((RUN_ALL <= func_idx) && (LAST_ALGO_FUNC >= func_idx));

    return 0;
}


