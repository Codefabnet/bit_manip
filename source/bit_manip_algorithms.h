#include "bit_manip.h"

extern uint8_t bit_pata;
extern uint8_t bit_patb;

extern union byte_bits byte__a;
extern union byte_bits byte__b;

void rightrot_bits(unsigned int in_word);
int rightrot_bit(unsigned int in_word);
void invert(int in_word, int pos, int num_bits);
void setbits(int * const out_word, const int pos,  const int num_bits,  const int in_word);
void pattern_byte_swap();
void byte_swap();
void nibble_swap();
