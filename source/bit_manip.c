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
    printf("****************************************\n");
    print_bit_patterns(byte__a, "byte__a");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

//**********************************************************
printf("a-b pattern byte swap.\n");
//**********************************************************
    // print the initial value of each pattern byte.
    printf("Initial value of each pattern byte. \n");
    printf("****************************************\n");
    printf("bit_pata = 0x%02X\n", bit_pata);
    printf("bit_patb = 0x%02X\n", bit_patb);
    printf("a-b swap in place using XOR.\n");
    printf("\n");

    // swap the bit patterns.
    bit_pata ^= bit_patb;
    bit_patb ^= bit_pata;
    bit_pata ^= bit_patb;

    // print the swapped value of each pattern byte.
    printf("Swapped value of each pattern byte.\n");
    printf("****************************************\n");
    printf("bit_pata = 0x%02X\n", bit_pata);
    printf("bit_patb = 0x%02X\n", bit_patb);
    printf("\n");

    pause_display_output(2);

//**********************************************************
printf("a-b byte swaps.\n");
//**********************************************************
    // print the initial value of each pattern bit_byte.
    printf("Print the initial value of each pattern bit_byte.\n");
    printf("****************************************\n");
    printf("byte__a.bit_byte = 0x%02X\n", byte__a.bit_byte);
    printf("byte__b.bit_byte = 0x%02X\n", byte__b.bit_byte);
    printf("a-b swap in place using XOR.\n");
    printf("\n");

    // swap the bit_byte.
    byte__a.bit_byte ^= byte__b.bit_byte;
    byte__b.bit_byte ^= byte__a.bit_byte;
    byte__a.bit_byte ^= byte__b.bit_byte;

    // print the swapped value of each bit_byte.
    printf("Print the swapped value of each bit_byte.\n");
    printf("****************************************\n");
    printf("byte__a.bit_byte = 0x%02X\n", byte__a.bit_byte);
    printf("byte__b.bit_byte = 0x%02X\n", byte__b.bit_byte);
    printf("\n");

    // print the current state of each union.
    printf("Print the current state of each union. \n");
    printf("****************************************\n");
    print_bit_patterns(byte__a, "byte__a");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

//**********************************************************
printf("a-b nibble swaps.\n");
//**********************************************************
    // swap high nibble.
    printf("a-b swap high nibble in place using XOR.\n");
    printf("****************************************\n");
    byte__a.nibble.nib_high ^= byte__b.nibble.nib_high;
    byte__b.nibble.nib_high ^= byte__a.nibble.nib_high;
    byte__a.nibble.nib_high ^= byte__b.nibble.nib_high;

    print_bit_patterns(byte__a, "byte__a");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

    // swap low nibble.
    printf("a-b swap low nibble in place using XOR.\n");
    printf("****************************************\n");
    byte__a.nibble.nib_low ^= byte__b.nibble.nib_low;
    byte__b.nibble.nib_low ^= byte__a.nibble.nib_low;
    byte__a.nibble.nib_low ^= byte__b.nibble.nib_low;

    print_bit_patterns(byte__a, "byte__a");
    print_bit_patterns(byte__b, "byte__b");

    pause_display_output(5);
    printf("\n");

//**********************************************************
printf("???\n");
//**********************************************************
    bit_total = 0;

    for (bit_count = 0; bit_count < CHAR_BIT; bit_count++) {
        bit_total += (bit_pata >> bit_count) & 1;
    }

    for (bit_count = 0; bit_count < CHAR_BIT; bit_count++) {
        bit_total += (bit_patb >> bit_count) & 1;
    }

    printf("bit_total = %d, avrg = %d\n",  bit_total, bit_total >> 1);

    printf("bit_pata = 0x%02X\n",  bit_pata & ((1 << NIBBLE_BIT) - 1) );
    printf("bit_patb = 0x%02X\n",  bit_patb );

    printf("%ld\n", (uint64_t)(1 << NIBBLE_BIT) - 1);
    printf("%ld\n", (uint64_t)~(~0 << NIBBLE_BIT));

    int out_word = 0xFF;

    pause_display_output(2);
    printf("\n");

    printf("\n\n************************************************************\n");
    printf("Set Bits\n");
    printf("************************************************************\n");
    setbits(&out_word, 3, 3, 0x32);

    printf("\n\n************************************************************\n");
    printf("Invert Bits\n");
    printf("************************************************************\n");
    invert(-1, 8, 3);

    printf("\n\n************************************************************\n");
    printf("Rotate Right Bits\n");
    printf("************************************************************\n");
    rightrot_bits(0x7F7F7F7FU);

}



