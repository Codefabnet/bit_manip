#include "bit_manip.h"
#include "bit_manip_algorithms.h"


uint8_t bit_pata = 0x55;
uint8_t bit_patb = 0xAA;

union byte_bits byte__a = {.bit_byte = 0x55};
union byte_bits byte__b = {.bit_byte = 0xAA};

void pattern_byte_swap()
{
    //**********************************************************
//    printf("==========================\n");
//    printf("| a-b pattern byte swap. |\n");
//    printf("==========================\n");
//    printf("\n");
    //**********************************************************
    // print the initial value of each pattern byte.
    printf("\tInitial value of each pattern byte.\n");
    printf("\t------------------------------------\n");
    printf("\tbit_pata = 0x%02X\n", bit_pata);
    printf("\tbit_patb = 0x%02X\n", bit_patb);
    printf("\n");
    printf("\tA-B swap in place using XOR.\n");
    printf("\n");

    // swap the bit patterns.
    bit_pata ^= bit_patb;
    bit_patb ^= bit_pata;
    bit_pata ^= bit_patb;

    // print the swapped value of each pattern byte.
    printf("\tSwapped value of each pattern byte.\n");
    printf("\t------------------------------------\n");
    printf("\tbit_pata = 0x%02X\n", bit_pata);
    printf("\tbit_patb = 0x%02X\n", bit_patb);
    printf("\n");

//    getchar();
    pause_for_input(10);
//    pause_display_output(10);
}

void byte_swap()
{
    //**********************************************************
//    printf("==========================\n");
//    printf("| a-b byte swaps.        |\n");
//    printf("==========================\n");
//    printf("\n");
    //**********************************************************
    // print the initial value of each pattern bit_byte.
    printf("\tPrint the initial value of each pattern bit_byte.\n");
    printf("\t--------------------------------------------------\n");
    printf("\tbyte__a.bit_byte = 0x%02X\n", byte__a.bit_byte);
    printf("\tbyte__b.bit_byte = 0x%02X\n", byte__b.bit_byte);
    printf("\n");
    printf("\tA-B swap in place using XOR.\n");
    printf("\n");

    // swap the bit_byte.
    byte__a.bit_byte ^= byte__b.bit_byte;
    byte__b.bit_byte ^= byte__a.bit_byte;
    byte__a.bit_byte ^= byte__b.bit_byte;

    // print the swapped value of each bit_byte.
    printf("\tPrint the swapped value of each bit_byte.\n");
    printf("\t------------------------------------------\n");
    printf("\tbyte__a.bit_byte = 0x%02X\n", byte__a.bit_byte);
    printf("\tbyte__b.bit_byte = 0x%02X\n", byte__b.bit_byte);
    printf("\n");

    // print the current state of each union.
    printf("\tPrint the current state of each union. \n");
    printf("\t----------------------------------------\n");
    print_bit_patterns(byte__a, "byte__a");
    printf("\n");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

//    getchar();
    pause_for_input(10);
//    pause_display_output(10);
}

void nibble_swap()
{
    //**********************************************************
//    printf("==========================\n");
//    printf("| a-b nibble swaps.      |\n");
//    printf("==========================\n");
//    printf("\n");
    //**********************************************************
    // swap high nibble.
    printf("\ta-b swap high nibble in place using XOR.\n");
    printf("\t-----------------------------------------\n");
    byte__a.nibble.nib_high ^= byte__b.nibble.nib_high;
    byte__b.nibble.nib_high ^= byte__a.nibble.nib_high;
    byte__a.nibble.nib_high ^= byte__b.nibble.nib_high;

    print_bit_patterns(byte__a, "byte__a");
    printf("\n");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

    // swap low nibble.
    printf("\ta-b swap low nibble in place using XOR.\n");
    printf("\t----------------------------------------\n");
    byte__a.nibble.nib_low ^= byte__b.nibble.nib_low;
    byte__b.nibble.nib_low ^= byte__a.nibble.nib_low;
    byte__a.nibble.nib_low ^= byte__b.nibble.nib_low;

    print_bit_patterns(byte__a, "byte__a");
    printf("\n");
    print_bit_patterns(byte__b, "byte__b");

//    getchar();
    pause_for_input(10);
//    pause_display_output(10);
    printf("\n");
}

//*****************************************************************************
// Function: setbits
//
// Description: For the given word, replace the bit field at the given width
//              and positiontion with the given bits.
//
// Parameters: out_word - Pointer to the word receiving the substitution.
//             pos      - The starting offset for the substitution.
//             num-bits - The number of bits to replace.
//             in_word  - The word containing the bits to use in thei
//                        substitution.
//
// Return: void
//
//*****************************************************************************
void setbits(int *const out_word,
             const int pos,
             const int num_bits,
             const int in_word)
{
   const int in_mask  = ~(~0 << num_bits);
   const int out_mask = in_mask << pos; 
   const int in_bits = (in_word & in_mask) << pos;


   printf("\tReplace %d bits at position %d in out_word\n",
          num_bits, pos);
   printf("\twith %d bits at beginning of in_word\n\n",
          num_bits);

   //****************************************************** 
   // Print the in_word bits
   //****************************************************** 
   printf("\tin_word  = ");
   print_bits(
           (union byte_bits)(uint8_t)in_word,
           CHAR_BIT,
           0);
   printf("\n");

   //****************************************************** 
   // Print the in_mask bits
   //****************************************************** 
   printf("\tin_mask  = ");
   print_bits((union byte_bits)(uint8_t)in_mask,
               num_bits,
               0);
   printf("\t<-input mask num_bits = %d\n", num_bits);

   printf("\t           --------");
   printf("\n");

   //****************************************************** 
   // Print the in_bits bits
   //****************************************************** 
   printf("\tin_bits  = ");
   print_bits(
           (union byte_bits)(uint8_t)(in_word & in_mask),
           num_bits,
           0);
   printf("\n");
   printf("\n");

   //****************************************************** 
   // Print the out_word bits
   //****************************************************** 
   printf("\tout_word = ");
   print_bits(
           (union byte_bits)(uint8_t)*out_word,
           CHAR_BIT,
           0);
   printf("\n");

   //****************************************************** 
   // Print the out_mask bits
   //****************************************************** 
   printf("\tout_mask = ");
   print_bits(
           (union byte_bits)(uint8_t)out_mask,
           num_bits + pos,
           pos + 1);
   printf("\t<");
   for (int i = 0; i < pos; i++)
      printf("-");
   printf("-output mask num_bits = %d\n", num_bits);

   //****************************************************** 
   // Print the new_bits bits
   //****************************************************** 
   printf("\tnew bits = ");
   print_bits(
           (union byte_bits)(uint8_t)in_bits,
           num_bits + pos,
           pos + 1);
   printf("\t<");
   for (int i = 0; i < pos; i++)
      printf("-");
   printf("-shift %d position\n", pos);

   printf("\t           --------");
   printf("\n");

   *out_word = (*out_word & ~out_mask) | in_bits;

   //****************************************************** 
   // Print the new out_word bits
   //****************************************************** 
   printf("\tout_word = ");
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

    printf("\t%s: mask = 0x%08X\n", __FUNCTION__, mask);


    printf("\tchanged in_word = 0x%08X\n", in_word ^= (mask << pos));
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
    printf("\t0x%X\n", (unsigned int)INT_MIN);
    word_print_bits(INT_MIN);
    printf("\t0x%X\n", (unsigned int)INT_MAX);
    word_print_bits(INT_MAX);
    printf("\t0x%X\n", (unsigned int)INT_MIN ^ (unsigned int)INT_MAX);
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




void uknown()
{
    //**********************************************************
    printf("==========================\n");
    printf("| ???                    |\n");
    printf("==========================\n");
    printf("\n");
    //**********************************************************
    int bit_count = 0;
    int bit_total = 0;

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


//    getchar();
    pause_for_input(10);
//    pause_display_output(10);
    printf("\n");
}
