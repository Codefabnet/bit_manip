#include <stdio.h>
#include "bit_manip.h"

void print_bits( union byte_bits byte_in, int end_bit, int start_bit)
{
   for (int i = 0; i < (CHAR_BIT - end_bit); i++)
      printf(" ");

   switch (end_bit) {
      case 8:
       printf("%01x", byte_in.bits.bit8);
       if (8 <= start_bit)
          break;
      case 7:
       printf("%01x", byte_in.bits.bit7);
       if (7 <= start_bit)
          break;
      case 6:
       printf("%01x", byte_in.bits.bit6);
       if (6 <= start_bit)
          break;
      case 5:
       printf("%01x", byte_in.bits.bit5);
       if (5 <= start_bit)
          break;
      case 4:
       printf("%01x", byte_in.bits.bit4);
       if (4 <= start_bit)
          break;
      case 3:
       printf("%01x", byte_in.bits.bit3);
       if (3 <= start_bit)
          break;
      case 2:
       printf("%01x", byte_in.bits.bit2);
       if (2 <= start_bit)
          break;
      case 1:
       printf("%01x", byte_in.bits.bit1);
       break;
      default:
       break;
   }

}

void word_print_bits(int in_word)
{
    printf("\t");
    print_bits(
            (union byte_bits)(uint8_t)(in_word >> (CHAR_BIT * 3)),
            CHAR_BIT,
            0);
    print_bits(
            (union byte_bits)(uint8_t)(in_word >> (CHAR_BIT * 2)),
            CHAR_BIT,
            0);
    print_bits(
            (union byte_bits)(uint8_t)(in_word >> CHAR_BIT),
            CHAR_BIT,
            0);
    print_bits(
            (union byte_bits)(uint8_t)in_word,
            CHAR_BIT,
            0);
    printf("\n");
}

void print_bit_patterns( union byte_bits byte_in, char *byte_name)
{
    printf("\t%s:\n", byte_name);
    printf("\t\tbit_byte = 0x%02X\n", byte_in.bit_byte);
    printf("\t\tnibbles  =   %01X", byte_in.nibble.nib_high);
    printf("%01X\n", byte_in.nibble.nib_low);
    printf("\t\tbits = ");
    print_bits(byte_in, CHAR_BIT, 0);
    printf("\n");

}
