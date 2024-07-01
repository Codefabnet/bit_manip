#include "bit_manip.h"

void setbits(int * const out_word, const int pos,  const int num_bits,  const int in_word)
{
   const int in_mask  = ~(~0 << num_bits);
   const int out_mask = in_mask << pos; 
   const int in_bits = (in_word & in_mask) << pos;


   printf("Replace %d bits at position %d in out_word\n",
          num_bits, pos);
   printf("with %d bits at beginning of in_word\n\n",
          num_bits);

   //****************************************************** 
   // Print the in_word bits
   //****************************************************** 
   printf("in_word  = ");
   print_bits(
           (union byte_bits)(uint8_t)in_word,
           CHAR_BIT,
           0);
   printf("\n");

   //****************************************************** 
   // Print the in_mask bits
   //****************************************************** 
   printf("in_mask  = ");
   print_bits((union byte_bits)(uint8_t)in_mask,
               num_bits,
               0);
   printf("<-input mask num_bits = %d\n", num_bits);

   printf("           --------");
   printf("\n");

   //****************************************************** 
   // Print the in_bits bits
   //****************************************************** 
   printf("in_bits  = ");
   print_bits(
           (union byte_bits)(uint8_t)(in_word & in_mask),
           num_bits,
           0);
   printf("\n");
   printf("\n");

   //****************************************************** 
   // Print the out_word bits
   //****************************************************** 
   printf("out_word = ");
   print_bits(
           (union byte_bits)(uint8_t)*out_word,
           CHAR_BIT,
           0);
   printf("\n");

   //****************************************************** 
   // Print the out_mask bits
   //****************************************************** 
   printf("out_mask = ");
   print_bits(
           (union byte_bits)(uint8_t)out_mask,
           num_bits + pos,
           pos + 1);
   printf("<");
   for (int i = 0; i < pos; i++)
      printf("-");
   printf("-output mask num_bits = %d\n", num_bits);

   //****************************************************** 
   // Print the new_bits bits
   //****************************************************** 
   printf("new bits = ");
   print_bits(
           (union byte_bits)(uint8_t)in_bits,
           num_bits + pos,
           pos + 1);
   printf("<");
   for (int i = 0; i < pos; i++)
      printf("-");
   printf("-shift %d position\n", pos);

   printf("           --------");
   printf("\n");

   *out_word = (*out_word & ~out_mask) | in_bits;

   //****************************************************** 
   // Print the new out_word bits
   //****************************************************** 
   printf("out_word = ");
   print_bits(
           (union byte_bits)(uint8_t)*out_word,
           CHAR_BIT,
           0);
   printf("\n");
}

//*****************************************************************************
// Function: invert
//
// Description: invert the num_bits starting at pos for the input word. 
//
// Parameters: in_word  - The word to change.
//             pos      - The start position for the change, beginning at LSB.
//             num_bits - The width of the change field.
//
// Return: 
//
//*****************************************************************************
void invert ( int in_word, int pos, int num_bits )
{
    int mask = ~(~0 << num_bits);

    printf("%s: mask = 0x%08X\n", __FUNCTION__, mask);


    printf("changed in_word = 0x%08X\n", in_word ^= (mask << pos));
    word_print_bits(in_word);
}

//*****************************************************************************
// Function: rightrot_bits
//
// Description:
//
// Parameters:
//
// Return:
//
//*****************************************************************************
void rightrot_bits(unsigned int in_word)
{
    printf("0x%X\n", (unsigned int)INT_MIN);
    word_print_bits(INT_MIN);
    printf("0x%X\n", (unsigned int)INT_MAX);
    word_print_bits(INT_MAX);
    printf("0x%X\n", (unsigned int)INT_MIN ^ (unsigned int)INT_MAX);
    word_print_bits(in_word);
//    in_word ^= INT_MIN;

    for (int i = 0; i < (CHAR_BIT * 4); i++) {
        in_word = rightrot_bit(in_word);
//        int lsb_set = in_word & 1;
//        printf("%2d: ", i);
//        word_print_bits(in_word);
//        in_word >>= 1;
//        if (lsb_set)
//            in_word |= INT_MIN;
    }
}

//*****************************************************************************
// Function: rightrot_bit
//
// Description:
//
// Parameters:
//
// Return:
//
//*****************************************************************************
int rightrot_bit(unsigned int in_word)
{
    int lsb_set = in_word & 1;
    pause_display_output(1);
    word_print_bits(in_word);
    in_word >>= 1;
    if (lsb_set)
        in_word |= INT_MIN;
   return in_word;
}
