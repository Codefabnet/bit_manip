#include "bit_manip.h"
#include "bit_manip_algorithms.h"


// Keeps the screen from scrolling for the given delay.
void pause_display_output(int delay)
{
    for (int i = 0; i < delay; i++) {
        usleep(500);
    }
}


// Keeps the screen from scrolling for the given delay.
uint32_t pause_for_input(int delay)
{
    char buf[5] = {0};
    fd_set rfds;
    struct timeval tv;
    int ret;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    tv.tv_sec = delay;
    tv.tv_usec = 0;

    printf("Select and/or press enter or wait...\n");
    printf("==========================================================\n");
    printf("1) pattern byte swap.   2) byte swap.    3) nibble swap. \n");
    printf("4) set bits.            5) invert bits.  6) rotate bits. \n");
    printf("\n");

    ret = select(1, &rfds, 0, 0, &tv);

    if (ret && FD_ISSET(0, &rfds)) {
        memset(buf, 0, sizeof(buf));
        ret = read(0, buf, sizeof(buf));
        printf("%c\n", buf[0]);
    }

    return (uint32_t)buf[0];

}



#define ALGO_FUNC_LIST \
    ALGO_FUNC_CALL(1, 0, 0, 0, 0, pattern_byte_swap, "pattern_byte_swap.") \
    ALGO_FUNC_CALL(2, 0, 0, 0, 0, byte_swap, "byte_swap.") \
    ALGO_FUNC_CALL(3, 0, 0, 0, 0, nibble_swap_two_bytes, "nibble_swap_two_bytes.") \
    ALGO_FUNC_CALL(4, 0xFF, 3, 3, 0x32, set_bits, "set_bits.") \
    ALGO_FUNC_CALL(5, 0, 0, 4, 0xFF, invert_bits, "invert_bits.") \
    ALGO_FUNC_CALL(6, 0, 0, 0, 0x7F7F7F7F, rotate_bits, "rotate_bits.  -->  <--")

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


uint32_t run_all()
{
    return 99;
}


uint32_t (* ptr_func[])() = {
    run_all,
#define ALGO_FUNC_CALL(func_id, output, pos, width, input, name, label) \
    algo_func##func_id,

ALGO_FUNC_LIST
#undef ALGO_FUNC_CALL
    NULL
};


