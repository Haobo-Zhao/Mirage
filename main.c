// The virtual machine is based on stack
// I think "stack machine" might not be a bad idea :)

// We will have A, B, C, D, E, F and other registers for the virtual machine

// Instruction set for the virtual machine:
// PSH 5       ; pushes 5 to the stack
// PSH 10      ; pushes 10 to the stack
// ADD         ; pops two values on top of the stack, adds them pushes to stack
// POP         ; pops the value on the stack, will also print it for debugging
// SET A 0     ; sets register A to 0
// HLT         ; stop the program


#include <stdio.h>
#include <stdbool.h>

// macros for sp (stack pointer) and ip(instruction pointer)
// #define sp (registers[SP])
// #define ip (registers[IP])

// TODO: rename `PSH` to `PUSH` and ``HLT` to `HALT`
typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

// Registers
// typedef enum {
//     A, B, C, D, E, F, IP, SP,
//     NUM_OF_REGISTERS
// } Registers;

// test program for the virtual machine
// all it does is to add 5 and 6, print out the result and then stop
const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

// Instruction pointer
int ip = 0;

// Stack pointer,
// Initialized to -1 here, since sp is increased before the value is pushed onto the stack
int sp = -1;

// Dah stack!
int stack[256];

// get an instruction
int fetch() {
    return program[ip];
}

bool running = true;

void eval(int instr) {
    switch (instr) {
        case PSH: {
            sp++;
            stack[sp] = program[++ip];
            break;
        }
        case POP: {
            // store the value at the top of the stack in `val_popped`
            // then decrement the stack pointer
            // and finally, print out the result
            int val_popped = stack[sp--];
            printf("popped %d\n", val_popped);
            break;
        }
        case ADD: {
            // first we pop the stack and store it in 'a'
            int a = stack[sp--];

            // and then we pop the top of the stack and store it in 'b'
            int b = stack[sp--];

            // then we add the result and push it back to the stack
            int result = b + a;
            // increment stack pointer before we push
            stack[++sp] = result;

            // all done!
            break;
        }
        case HLT: {
            running = false;
            break;
        }
    }
}

int main() {
    while (running) {
        eval(fetch());
        ip++; // increment the ip every iteration
    }
}
