#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "bit_manip.h"
#include "bit_manip_algorithms.h"



int main(void)
{

    // print the initial state of each union.
    printf("\n");
    printf("\tInitial state of each union.\n");
    printf("\t-----------------------------\n");
    print_bit_patterns(byte__a, "byte__a");
    printf("\n");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");


    printf("==========================\n");
    printf("| a-b pattern byte swap. |\n");
    printf("==========================\n");
    printf("\n");
    pattern_byte_swap();

    printf("==========================\n");
    printf("| a-b byte swaps.        |\n");
    printf("==========================\n");
    printf("\n");
    byte_swap();

    printf("==========================\n");
    printf("| a-b nibble swaps.      |\n");
    printf("==========================\n");
    printf("\n");
    nibble_swap();

    printf("==========================\n");
    printf("| set bits.              |\n");
    printf("==========================\n");
    printf("\n");
    int out_word = 0xFF;
    setbits(&out_word, 3, 3, 0x32);
    printf("\n");

    printf("==========================\n");
    printf("| invert.                |\n");
    printf("==========================\n");
    printf("\n");
    invert(-1, 8, 3);
    printf("\n");

    printf("==========================\n");
    printf("| rightrot_bits.         |\n");
    printf("==========================\n");
    printf("\n");
    rightrot_bits(0x7F7F7F7FU);

}



