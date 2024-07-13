#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "bit_manip.h"


uint8_t bit_pata = 0x55;
uint8_t bit_patb = 0xaa;


int main(void)
{
    int bit_count = 0;
    int bit_total = 0;

    union byte_bits byte__a = {.bit_byte = bit_pata};
    union byte_bits byte__b = {.bit_byte = bit_patb};

    // print the initial state of each union.
    printf("Initial state of each union.\n");
    printf("*****************************\n");
    print_bit_patterns(byte__a, "byte__a");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

    //**********************************************************
    printf("a-b pattern byte swap.\n");
    printf("***********************\n");
    //**********************************************************
    // print the initial value of each pattern byte.
    printf("\tInitial value of each pattern byte.\n");
    printf("\t************************************\n");
    printf("\tbit_pata = 0x%02X\n", bit_pata);
    printf("\tbit_patb = 0x%02X\n", bit_patb);
    printf("\ta-b swap in place using XOR.\n");
    printf("\n");

    // swap the bit patterns.
    bit_pata ^= bit_patb;
    bit_patb ^= bit_pata;
    bit_pata ^= bit_patb;

    // print the swapped value of each pattern byte.
    printf("\tSwapped value of each pattern byte.\n");
    printf("\t************************************\n");
    printf("\tbit_pata = 0x%02X\n", bit_pata);
    printf("\tbit_patb = 0x%02X\n", bit_patb);
    printf("\n");

    pause_display_output(2);

    //**********************************************************
    printf("a-b byte swaps.\n");
    printf("****************\n");
    //**********************************************************
    // print the initial value of each pattern bit_byte.
    printf("\tPrint the initial value of each pattern bit_byte.\n");
    printf("\t**************************************************\n");
    printf("\tbyte__a.bit_byte = 0x%02X\n", byte__a.bit_byte);
    printf("\tbyte__b.bit_byte = 0x%02X\n", byte__b.bit_byte);
    printf("\ta-b swap in place using XOR.\n");
    printf("\n");

    // swap the bit_byte.
    byte__a.bit_byte ^= byte__b.bit_byte;
    byte__b.bit_byte ^= byte__a.bit_byte;
    byte__a.bit_byte ^= byte__b.bit_byte;

    // print the swapped value of each bit_byte.
    printf("\tPrint the swapped value of each bit_byte.\n");
    printf("\t******************************************\n");
    printf("\tbyte__a.bit_byte = 0x%02X\n", byte__a.bit_byte);
    printf("\tbyte__b.bit_byte = 0x%02X\n", byte__b.bit_byte);
    printf("\n");

    // print the current state of each union.
    printf("\tPrint the current state of each union. \n");
    printf("\t****************************************\n");
    print_bit_patterns(byte__a, "byte__a");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

    //**********************************************************
    printf("a-b nibble swaps.\n");
    printf("******************\n");
    //**********************************************************
    // swap high nibble.
    printf("\ta-b swap high nibble in place using XOR.\n");
    printf("\t*****************************************\n");
    byte__a.nibble.nib_high ^= byte__b.nibble.nib_high;
    byte__b.nibble.nib_high ^= byte__a.nibble.nib_high;
    byte__a.nibble.nib_high ^= byte__b.nibble.nib_high;

    print_bit_patterns(byte__a, "byte__a");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

    // swap low nibble.
    printf("\ta-b swap low nibble in place using XOR.\n");
    printf("\t****************************************\n");
    byte__a.nibble.nib_low ^= byte__b.nibble.nib_low;
    byte__b.nibble.nib_low ^= byte__a.nibble.nib_low;
    byte__a.nibble.nib_low ^= byte__b.nibble.nib_low;

    print_bit_patterns(byte__a, "byte__a");
    print_bit_patterns(byte__b, "byte__b");

    pause_display_output(5);
    printf("\n");

    //**********************************************************
    printf("???\n");
    printf("****************************************\n");
    //**********************************************************
    bit_total = 0;

    for (bit_count = 0; bit_count < CHAR_BIT; bit_count++) {
        bit_total += (bit_pata >> bit_count) & 1;
    }

    for (bit_count = 0; bit_count < CHAR_BIT; bit_count++) {
        bit_total += (bit_patb >> bit_count) & 1;
    }

    printf("\tbit_total = %d, avrg = %d\n",  bit_total, bit_total >> 1);

    printf("\tbit_pata = 0x%02X\n",  bit_pata & ((1 << NIBBLE_BIT) - 1) );
    printf("\tbit_patb = 0x%02X\n",  bit_patb );

    printf("\t%ld\n", (uint64_t)(1 << NIBBLE_BIT) - 1);
    printf("\t%ld\n", (uint64_t)~(~0 << NIBBLE_BIT));

    int out_word = 0xFF;

    pause_display_output(2);
    printf("\n");

    printf("Set Bits\n");
    printf("*********\n");
    setbits(&out_word, 3, 3, 0x32);
    printf("\n");

    printf("Invert Bits\n");
    printf("************\n");
    invert(-1, 8, 3);
    printf("\n");

    printf("Rotate Right Bits\n");
    printf("******************\n");
    rightrot_bits(0x7F7F7F7FU);

}



