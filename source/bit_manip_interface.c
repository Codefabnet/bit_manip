#include "bit_manip.h"
#include "bit_manip_algorithms.h"




//*****************************************************************************
// Function: pause_display_output
//
// Description: Sleep wait for the specified delay time.
//
// Parameters: delay - Delay in multiples of 500 usec.
//
// Return: void
//
//*****************************************************************************
void pause_display_output(int delay)
{
    for (int i = 0; i < delay; i++) {
        usleep(500);
    }
}


//*****************************************************************************
// Function: pause_for_input
//
// Description: Wait specified delay time, or for enter key.
//
// Parameters: delay - Length of time to wait.
//
// Return: First character in the buffer when enter key is pressed.
//
//*****************************************************************************
uint32_t pause_for_input(int delay)
{
    char buf[5] = {0};
    fd_set rfds;
    struct timeval tv;
    int ret;

    // prompt for the function index for a desired bit exercise.
    printf("Select and/or press enter or wait...\n");
    printf("==========================================================\n");
    printf("1) pattern byte swap.   2) byte swap.    3) nibble swap. \n");
    printf("4) set bits.            5) invert bits.  6) rotate bits. \n");
    printf("\n");

    // setup timeval struct.
    tv.tv_sec = delay;
    tv.tv_usec = 0;

    // setup descriptors for the select call, using stdin.
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    ret = select(1, &rfds, 0, 0, &tv);

    // check for line entry as indicated by enter key press.
    if (ret && FD_ISSET(0, &rfds)) {
        memset(buf, 0, sizeof(buf));
        ret = read(0, buf, sizeof(buf));
        printf("%c\n", buf[0]);
    }

    // If there was a line read, return the first byte entered, otherwise
    // the buffer will still contain zero and that will be the return value.
    return (uint32_t)buf[0];

}


//*****************************************************************************
// Function: run_all
//
// Description: Currently, used to end program without calling more functions.
//
// Parameters:
//
// Return: An invalid function index, causes the outer while loop to terminate.
//
//*****************************************************************************
uint32_t run_all()
{
    return 99;
}



//************************************************************
// X-Macros to create wrapper functions and add them to an
// array to be called using an enumerated index.
//************************************************************
#if defined(MULTI_PASS_TESTS) // algo funcs called more than once

//************************************************************
// struct bit_desc members represent the common parameters
// related to the bit manipulation exercises.
//
//  typedef struct bit_desc {
//      out_word;   // pointer to the word being modified.
//      offset;     // position of the modification.
//      num_bits;i  // number of bits being modified.
//      in_word;    // bit donor or single word operand.
//  } bit_desc_t;
//
// By passing a pointer to a bit_desc array, the wrapper
// functions may call the algorithm functions multiple times
// with differing parameter.
//************************************************************

// tests which use out_word expect it to be passed by reference.
uint32_t out_wordx0 = 0xFF;
uint32_t out_wordx1 = 0xF7;

// parameter objects as needed
bit_desc_t  bit_parm4x0 = {&out_wordx0, 3, 3, 0x32};
bit_desc_t  bit_parm4x1 = {&out_wordx1, 0, 4, 0xF4};
bit_desc_t  bit_parm5x0 = {0, 0, 4, 0xFF};
bit_desc_t  bit_parm6x0 = {0, 0, 0, 0x7F7F7F7F};

// parameter object arrays, accessed by wrapper functions by
// pointer dereference. NULL terminated to avoid using a separate
// count parameter.
bit_desc_t  *bit_parm1[] = {NULL};
bit_desc_t  *bit_parm2[] = {NULL};
bit_desc_t  *bit_parm3[] = {NULL};
bit_desc_t  *bit_parm4[] = {&bit_parm4x0, &bit_parm4x1, NULL};
bit_desc_t  *bit_parm5[] = {&bit_parm5x0, NULL};
bit_desc_t  *bit_parm6[] = {&bit_parm6x0, NULL};

#define ALGO_FUNC_LIST \
    ALGO_FUNC_CALL(1, pattern_byte_swap, "pattern_byte_swap.") \
    ALGO_FUNC_CALL(2, byte_swap, "byte_swap.") \
    ALGO_FUNC_CALL(3, nibble_swap_two_bytes, "nibble_swap_two_bytes.") \
    ALGO_FUNC_CALL(4, set_bits, "set_bits.") \
    ALGO_FUNC_CALL(5, invert_bits, "invert_bits.") \
    ALGO_FUNC_CALL(6, rotate_bits, "rotate_bits.  -->  <--")

// define the wrapper functions dynamicaly, using x macro.
#define ALGO_FUNC_CALL(func_id, name, label) \
    uint32_t algo_func##func_id() \
    { \
       printf("==========================\n"); \
       printf("| %s\n", label); \
       printf("==========================\n"); \
       printf("\n"); \
       uint32_t idx = 0; \
       do { \
          name(bit_parm##func_id[idx]); \
          printf("\n"); \
          idx++; \
       } while (bit_parm##func_id[idx]); \
       return pause_for_input(10); \
    }

    ALGO_FUNC_LIST
#undef ALGO_FUNC_CALL

#else // Single else multi pass x macros.

// macros for single pass wrapper functions pass all parameters in the macro
#define ALGO_FUNC_LIST \
    ALGO_FUNC_CALL(1, 0, 0, 0, 0, pattern_byte_swap, "pattern_byte_swap.") \
    ALGO_FUNC_CALL(2, 0, 0, 0, 0, byte_swap, "byte_swap.") \
    ALGO_FUNC_CALL(3, 0, 0, 0, 0, nibble_swap_two_bytes, "nibble_swap_two_bytes.") \
    ALGO_FUNC_CALL(4, 0xFF, 3, 3, 0x32, set_bits, "set_bits.") \
    ALGO_FUNC_CALL(5, 0, 0, 4, 0xFF, invert_bits, "invert_bits.") \
    ALGO_FUNC_CALL(6, 0, 0, 0, 0x7F7F7F7F, rotate_bits, "rotate_bits.  -->  <--")

// define the wrapper functions dynamically, using x macro.
#define ALGO_FUNC_CALL(func_id, output, pos, width, input, name, label) \
    uint32_t algo_func##func_id() \
    { \
       uint32_t out_word = output; \
       bit_desc_t  bit_parm = { \
           .out_word = &out_word,  \
           .offset   = pos,  \
           .num_bits = width, \
           .in_word  = input    \
       }; \
       printf("==========================\n"); \
       printf("| %s\n", label); \
       printf("==========================\n"); \
       printf("\n"); \
       name(&bit_parm); \
       printf("\n"); \
       return pause_for_input(10); \
    }

    ALGO_FUNC_LIST
#undef ALGO_FUNC_CALL
#endif


    // array of wrapper functions.
    uint32_t (* ptr_func[])() = {
        run_all,

       // define the array elements dynamically, using a variadac version of
       // the x macro to accommodate both single and multi pass versions of
       // the list.
#define ALGO_FUNC_CALL(func_id, ...) \
        algo_func##func_id,
        ALGO_FUNC_LIST
#undef ALGO_FUNC_CALL
        NULL
    };

