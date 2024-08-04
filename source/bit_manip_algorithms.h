#include "bit_manip.h"


// For rotate bits exercise.
enum rotate_direction {
    rotate_left,
    rotate_right
};

// Index into the function pointer array of exercises.
enum algo_funcs {
    RUN_ALL,
    FIRST_ALGO_FUNC = 1,
    PATTERN_BYTE_SWAP = FIRST_ALGO_FUNC,
    BYTE_SWAP,
    NIBBLE_SWAP_TWO_BYTES,
    SET_BITS,
    INVERT_BITS,
    ROTATE_BITS,
    LAST_ALGO_FUNC = ROTATE_BITS
};

typedef struct bit_desc {
    uint32_t *const out_word;  // pointer to the word being modified.
    const uint32_t offset;     // position of the modification.
    const uint32_t num_bits;   // number of bits being modified.
    uint32_t in_word;          // bit donor or single word operand.
} bit_desc_t;

// Function pointer array of exercises.
extern uint32_t (* ptr_func[])();

// Common byte swap function.
static inline void swap_bytes(uint8_t *byte__a, uint8_t *byte__b)
{
    *byte__a ^= *byte__b;
    *byte__b ^= *byte__a;
    *byte__a ^= *byte__b;
}

// Algorithm functions.
void rotate_bits(bit_desc_t *bit_desc);
uint32_t rotate_bit(uint32_t in_word, const enum rotate_direction direction);
void invert_bits(bit_desc_t *bit_desc);
void set_bits(bit_desc_t *bit_desc);
void pattern_byte_swap(bit_desc_t *bit_desc);
void byte_swap(bit_desc_t *bit_desc);
void nibble_swap_two_bytes(bit_desc_t *bit_desc);
void nibble_swap_one_byte(bit_desc_t *bit_desc);
