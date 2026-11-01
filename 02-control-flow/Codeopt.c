#include <stdio.h>
#include <stdint.h>

enum {
    OP_XOR  = 1,
    OP_OUT  = 2,
    OP_HALT = 3
};

static const uint8_t code[] = {
    
    0x12,               

    
    OP_XOR, 0x2d,       
    OP_OUT,

    OP_XOR, 0x09,       
    OP_OUT,

    OP_XOR, 0x00,       
    OP_OUT,

    OP_XOR, 0x03,       
    OP_OUT,

    OP_XOR, 0x4f,       
    OP_OUT,

    OP_XOR, 0x77,       
    OP_OUT,

    OP_XOR, 0x38,       
    OP_OUT,

    OP_XOR, 0x1d,       
    OP_OUT,

    OP_XOR, 0x1e,       
    OP_OUT,

    OP_XOR, 0x08,       
    OP_OUT,

    OP_HALT
};

int main(void)
{
    uint8_t reg = 0;
    for (size_t pc = 0; pc < sizeof(code); )
    {
        uint8_t op = code[pc++];
        if (op == OP_HALT)
            break;
        if (op == OP_XOR)
        {
            if (pc >= sizeof(code))
                return 1;
            reg ^= code[pc++];
        }
        else if (op == OP_OUT)
        {
            putchar(reg);
        }
        else
        {
            reg = op;
            reg ^= 0x5a;
            putchar(reg);
        }
    }
    putchar('\n');
    return 0;
}