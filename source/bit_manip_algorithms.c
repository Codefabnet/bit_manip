#include "bit_manip.h"
#include "bit_manip_algorithms.h"


static uint8_t bit_pata = 0x55;
static uint8_t bit_patb = 0xAA;

static union byte_bits byte__a = {.bit_byte = 0x55};
static union byte_bits byte__b = {.bit_byte = 0xAA};


//*****************************************************************************
// Function: pattern_byte_swap
//
// Description: Swap 2 bytes in place using XOR.
//
// Parameters: none
//
// Return: void
//
//*****************************************************************************
void pattern_byte_swap(bit_desc_t *bit_desc)
{
    // print the initial value of each pattern byte.
    printf("\tInitial value of each pattern byte.\n");
    printf("\t------------------------------------\n");
    printf("\tbit_pata = 0x%02X\n", bit_pata);
    printf("\tbit_patb = 0x%02X\n", bit_patb);
    printf("\n");
    printf("\tA-B swap in place using XOR.\n");
    printf("\n");

    // swap the bit patterns.
    swap_bytes(&bit_pata, &bit_patb);

    // print the swapped value of each pattern byte.
    printf("\tSwapped value of each pattern byte.\n");
    printf("\t------------------------------------\n");
    printf("\tbit_pata = 0x%02X\n", bit_pata);
    printf("\tbit_patb = 0x%02X\n", bit_patb);
    printf("\n");
}


//*****************************************************************************
// Function: byte_swap
//
// Description: Swap 2 bytes in place using XOR.
//
// Parameters: none
//
// Return: void
//
//*****************************************************************************
void byte_swap(bit_desc_t *bit_desc)
{
    // print the initial value of each bit_byte.
    printf("\tInitial value of each bit_byte.\n");
    printf("\t--------------------------------------------------\n");
    print_bit_patterns(byte__a, "byte__a");
    printf("\n");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");
    printf("\tA-B swap in place using XOR.\n");
    printf("\n");

    // swap the bit_byte.
    swap_bytes(&byte__a.bit_byte, &byte__b.bit_byte );

    // print the swapped value of each bit_byte.
    printf("\tSwapped value of each bit_byte.\n");
    printf("\t------------------------------------------\n");
    print_bit_patterns(byte__a, "byte__a");
    printf("\n");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

}


//*****************************************************************************
// Function: nibble_swap_two_bytes
//
// Description: Swap nibbles from 2 bytes in place using XOR
//
// Parameters: none
//
// Return: void
//
//*****************************************************************************
void nibble_swap_two_bytes(bit_desc_t *bit_desc)
{
    // print the initial value of each bit_byte.
    printf("\tInitial value of each bit_byte.\n");
    printf("\t--------------------------------------------------\n");
    print_bit_patterns(byte__a, "byte__a");
    printf("\n");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

    // swap high nibble.
    printf("\ta-b swap high nibble in place using XOR.\n");
    printf("\t-----------------------------------------\n");
//    swap_bytes(&byte__a.nibble.nib_high , &byte__b.nibble.nib_high );
    byte__a.nibble.nib_high ^= byte__b.nibble.nib_high;
    byte__b.nibble.nib_high ^= byte__a.nibble.nib_high;
    byte__a.nibble.nib_high ^= byte__b.nibble.nib_high;

    print_nibbles(byte__a, "byte__a");
    print_nibbles(byte__b, "byte__b");
    printf("\n");

    // swap low nibble.
    printf("\ta-b swap low nibble in place using XOR.\n");
    printf("\t----------------------------------------\n");
    byte__a.nibble.nib_low ^= byte__b.nibble.nib_low;
    byte__b.nibble.nib_low ^= byte__a.nibble.nib_low;
    byte__a.nibble.nib_low ^= byte__b.nibble.nib_low;

    print_nibbles(byte__a, "byte__a");
    print_nibbles(byte__b, "byte__b");
    printf("\n");

    // print the current value of each bit_byte.
    printf("\tCurrent value of each bit_byte.\n");
    printf("\t--------------------------------------------------\n");
    print_bit_patterns(byte__a, "byte__a");
    printf("\n");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

}

//TODO: find simplest method for swapping nibbles in a byte.
// Bitwise operator don't work on operands smaller than a byte.
//*****************************************************************************
// Function: nibble_swap_one_byte
//
// Description: Swap nibbles in a single byte ???
//
// Parameters: none
//
// Return: void
//
//*****************************************************************************
void nibble_swap_one_byte(bit_desc_t *bit_desc)
{
    // print the initial value of each bit_byte.
    printf("\tInitial value of each bit_byte.\n");
    printf("\t--------------------------------------------------\n");
    print_bit_patterns(byte__a, "byte__a");
    printf("\n");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

    // swap high nibble.
    printf("\ta-b swap high nibble in place using XOR.\n");
    printf("\t-----------------------------------------\n");
    byte__a.nibble.nib_high ^= byte__a.nibble.nib_low;
    byte__a.nibble.nib_high ^= byte__a.nibble.nib_low;
    byte__a.nibble.nib_high ^= byte__a.nibble.nib_low;

    print_nibbles(byte__a, "byte__a");
    printf("\n");
    print_nibbles(byte__b, "byte__b");
    printf("\n");

    // swap low nibble.
    printf("\ta-b swap low nibble in place using XOR.\n");
    printf("\t----------------------------------------\n");
    byte__a.nibble.nib_low ^= byte__b.nibble.nib_low;
    byte__b.nibble.nib_low ^= byte__a.nibble.nib_low;
    byte__a.nibble.nib_low ^= byte__b.nibble.nib_low;

    print_nibbles(byte__a, "byte__a");
    printf("\n");
    print_nibbles(byte__b, "byte__b");
    printf("\n");

    // print the current value of each bit_byte.
    printf("\tcurrent value of each bit_byte.\n");
    printf("\t--------------------------------------------------\n");
    print_bit_patterns(byte__a, "byte__a");
    printf("\n");
    print_bit_patterns(byte__b, "byte__b");
    printf("\n");

}


//*****************************************************************************
// Function: set_bits
//
// Description: For the given word, replace the bit field at the given width
//              and position with the given bits.
//
// Parameters: out_word - Pointer to the word receiving the substitution.
//             offset      - The starting offset for the substitution.
//             num_bits - The number of bits to replace.
//             in_word  - The word containing the bits to use in the
//                        substitution.
//
// Return: void
//
//*****************************************************************************
void set_bits(bit_desc_t *bit_desc)
{
   const uint32_t in_mask  = ~(~0 << bit_desc->num_bits);
   const uint32_t out_mask = in_mask << bit_desc->offset;
   const uint32_t in_bits = (bit_desc->in_word & in_mask) << bit_desc->offset;


   printf("\tReplace %d bits at position %d in out_word\n",
           bit_desc->num_bits,
           bit_desc->offset);
   printf("\twith %d bits at beginning of in_word\n\n",
           bit_desc->num_bits);

   //******************************************************
   // Print the in_word bits
   //******************************************************
   printf("\tin_word  = ");
   print_bits(
           (union byte_bits)(uint8_t)bit_desc->in_word,
           CHAR_BIT,
           0);
   printf("\n");

   //******************************************************
   // Print the in_mask bits
   //******************************************************
   printf("\tin_mask  = ");
   print_bits((union byte_bits)(uint8_t)in_mask, bit_desc->num_bits, 0);
   printf("\t<-input mask num_bits = %d\n", bit_desc->num_bits);

   printf("\t           --------\n");

   //******************************************************
   // Print the in_bits bits
   //******************************************************
   printf("\tin_bits  = ");
   print_bits(
           (union byte_bits)(uint8_t)(bit_desc->in_word & in_mask),
           bit_desc->num_bits,
           0);
   printf("\n\n");

   //******************************************************
   // Print the out_word bits
   //******************************************************
   printf("\tout_word = ");
   print_bits(
           (union byte_bits)(uint8_t)*bit_desc->out_word,
           CHAR_BIT,
           0);
   printf("\n");

   //******************************************************
   // Print the out_mask bits
   //******************************************************
   printf("\tout_mask = ");
   print_bits(
           (union byte_bits)(uint8_t)out_mask,
           bit_desc->num_bits + bit_desc->offset,
           bit_desc->offset + 1);

   printf("\t<");
   for (int i = 0; i < bit_desc->offset; i++)
      printf("-");

   printf("-output mask num_bits = %d\n", bit_desc->num_bits);

   //******************************************************
   // Print the new_bits bits
   //******************************************************
   printf("\tnew bits = ");
   print_bits(
           (union byte_bits)(uint8_t)in_bits,
           bit_desc->num_bits + bit_desc->offset,
           bit_desc->offset + 1);

   printf("\t<");
   for (int i = 0; i < bit_desc->offset; i++)
      printf("-");

   printf("-shift %d position\n", bit_desc->offset);

   printf("\t           --------\n");

   *bit_desc->out_word = (*bit_desc->out_word & ~out_mask) | in_bits;

   //******************************************************
   // Print the new out_word bits
   //******************************************************
   printf("\tout_word = ");
   print_bits(
           (union byte_bits)(uint8_t)*bit_desc->out_word,
           CHAR_BIT,
           0);
   printf("\n");
}

//**************************************************************************
// Function: invert
//
// Description: invert the num_bits starting at offset for the input word.
//
// Parameters: in_word  - The word to change.
//             offset   - The start position for the change, beginning at LSB.
//             num_bits - The width of the change field.
//
// Return: void
//
//**************************************************************************
void invert_bits(bit_desc_t *bit_desc)
{
   const uint32_t mask = (~(~0 << bit_desc->num_bits)) << bit_desc->offset;

   printf("\tInvert  %d bits at position %d in in_word\n", bit_desc->num_bits, bit_desc->offset);

   //******************************************************
   // Print the in_word bits
   //******************************************************
   printf("\tin_word  = ");
   print_bits(
           (union byte_bits)(uint8_t)bit_desc->in_word,
           CHAR_BIT,
           0);
   printf("\n");

   //******************************************************
   // Print the mask bits
   //******************************************************
   printf("\tmask     = ");
   print_bits((union byte_bits)(uint8_t)mask,
               bit_desc->num_bits + bit_desc->offset,
               bit_desc->offset + 1);
   printf("   \t<-mask %d bits, shifted %d\n", bit_desc->num_bits, bit_desc->offset);

   printf("\t           --------\n");



   bit_desc->in_word ^= mask;
   printf("\tin_word  = ");
   print_bits(
           (union byte_bits)(uint8_t)bit_desc->in_word,
           CHAR_BIT,
           0);
   printf("\n\n");
}

//**************************************************************************
// Function: rotate_bits
//
// Description:
//
// Parameters:
//
// Return:
//
//**************************************************************************
void rotate_bits(bit_desc_t *bit_desc)
{
    printf("\t0x%X\n", (uint32_t)INT_MIN);
    word_print_bits(INT_MIN);
    printf("\t0x%X\n", (uint32_t)INT_MAX);
    word_print_bits(INT_MAX);
    printf("\t0x%X\n", (uint32_t)INT_MIN ^ (uint32_t)INT_MAX);
    word_print_bits(bit_desc->in_word);
//    in_word ^= INT_MIN;

    for (int i = 0; i < (CHAR_BIT * 4); i++) {
        bit_desc->in_word = rotate_bit(bit_desc->in_word, 1);
    }

    for (int i = 0; i < (CHAR_BIT * 4); i++) {
        bit_desc->in_word = rotate_bit(bit_desc->in_word, 0);
    }
}


//**************************************************************************
// Function: rotate_bit
//
// Description:
//
// Parameters:
//
// Return:
//
//**************************************************************************
uint32_t rotate_bit(uint32_t in_word, const enum rotate_direction direction)
{
    const uint32_t xfer_bit = (rotate_right == direction) ? INT_MIN : 1;
    const uint32_t xfer_bit_set = (rotate_right == direction) ?
                                  in_word & 1 : in_word & INT_MIN;

    pause_display_output(50);
    word_print_bits(in_word);

    in_word = (rotate_right == direction) ? in_word >> 1 : in_word << 1;

    if (xfer_bit_set)
        in_word |= xfer_bit;
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
    uint32_t bit_count = 0;
    uint32_t bit_total = 0;

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


    pause_for_input(10);
    printf("\n");
}
