#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <unistd.h>
#include <sys/time.h>

#define NIBBLE_BIT (CHAR_BIT / 2)

union byte_bits {
    struct {
        uint8_t     bit1 : 1;
        uint8_t     bit2 : 1;
        uint8_t     bit3 : 1;
        uint8_t     bit4 : 1;
        uint8_t     bit5 : 1;
        uint8_t     bit6 : 1;
        uint8_t     bit7 : 1;
        uint8_t     bit8 : 1;
    }bits;
    struct {
        uint8_t nib_low : 4;
        uint8_t nib_high  : 4;
    }nibble;
    uint8_t bit_byte;
};


// Keeps the screen from scrolling for the given delay.
static inline void pause_display_output(int delay)
{
    for (int i = 0; i < delay; i++) {
        putchar('.');
        fflush(stdout);
        sleep(1);
    }
}


void print_bit_patterns( union byte_bits byte_in, char *byte_name);
void print_bits( union byte_bits byte_in, int end_bit, int start_bit);
void word_print_bits(int in_word);

void rightrot_bits(unsigned int in_word);
int rightrot_bit(unsigned int in_word);
void invert(int in_word, int pos, int num_bits);
void setbits(int * const out_word, const int pos,  const int num_bits,  const int in_word);
