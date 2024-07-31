#include <stdio.h>
#include "bit_manip.h"


//*****************************************************************************
// Function: print_bits
//
// Description: Print the bitfield of the given byte, as defined by the start
//              and end parameters.
//
// Parameters: byte_in - Union with bitfields defined for the given byte.
//             end_bit - MSB of the given bitfield.
//             start_bit - LSB of the given bitfield.
//
// Return: void
//
//*****************************************************************************
void print_bits( union byte_bits byte_in, int end_bit, int start_bit)
{
   // Right justify based on the pattern end bit position.
   for (int i = 0; i < (CHAR_BIT - end_bit); i++)
      printf(" ");

   // Print bits in the union, starting with the end bit position, falling
   // through to the next bit until reaching the start bit.
   switch (end_bit) {

#define case_macro(bitp) \
       case bitp: \
           printf("%01x", byte_in.bits.bit##bitp); \
           if (bitp <= start_bit) \
              break;

       // One case statement for each bit
       case_macro(8)
       case_macro(7)
       case_macro(6)
       case_macro(5)
       case_macro(4)
       case_macro(3)
       case_macro(2)
       case_macro(1)
#undef case_macro

       default:
          break;
   }

}


//*****************************************************************************
// Function: word_print_bits
//
// Description: Prints the ones and zeroes bit pattern for the given word.
//
// Parameters: in_word - The word to print.
//
// Return: void
//
//*****************************************************************************
void word_print_bits(uint32_t in_word)
{

#define print_macro(i) \
    print_bits((union byte_bits)(uint8_t)(in_word >> (CHAR_BIT * i)), \
            CHAR_BIT, \
            0);

    // print the bit pattern for each byte in the given word.
    printf("\t");
    print_macro(3);
    print_macro(2);
    print_macro(1);
    print_macro(0);
#undef print_macro

    printf("\n");
}


//*****************************************************************************
// Function: print_bit_patterns
//
// Description: Prints the different number representations in
//              the byte_bits union.
//
// Parameters: byte_in - the union byte_bits object to print.
//
// Return: void
//
//*****************************************************************************
void print_bit_patterns( union byte_bits byte_in, char *byte_name)
{
    printf("\t%s:\n", byte_name);
    printf("\t\tbit_byte = 0x%02X\n", byte_in.bit_byte);
    printf("\t\tbits = ");
    print_bits(byte_in, CHAR_BIT, 0);
    printf("\n");

}

//*****************************************************************************
// Function: print_nibbles
//
// Description: Prints the high and low nibbles of the byte_bits union.
//
// Parameters: byte_in - the union byte_bits object to print.
//
// Return: void
//
//*****************************************************************************
void print_nibbles( union byte_bits byte_in, char *byte_name)
{
    printf("\t%s: high/low nibble", byte_name);
    printf("\t%01X", byte_in.nibble.nib_high);
    printf("/%01X\n", byte_in.nibble.nib_low);

}
