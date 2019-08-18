// The virtual machine is based on stack
// I think "stack machine" might not be a bad idea :)

// We will have A, B, C, D, E, F and other registers for the virtual machine

// Instruction set for the virtual machine:
// PUSH 5       ; pushes 5 to the stack
// PUSH 10      ; pushes 10 to the stack
// ADD         ; pops two values on top of the stack, adds them pushes to stack
// POP         ; pops the value on the stack, will also print it for debugging
// SET A 0     ; sets register A to 0
// HALT         ; stop the virtual machine


#include <stdio.h>
#include <stdbool.h>

// #define sp (registers[SP])
// #define ip (registers[IP])

// macros for sp (stack pointer) and ip(instruction pointer)
// #define sp (registers[SP])
// #define ip (registers[IP])

typedef enum {
    PUSH,
    ADD,
    POP,
    SET,
    HALT
} InstructionSet;

// Registers
// typedef enum {
//     A, B, C, D, E, F, IP, SP,
//     NUM_OF_REGISTERS
// } Registers;
// int registers[NUM_OF_REGISTERS];


// test program for the virtual machine
// all it does is to add 5 and 6, print out the result and then stop
const int instruction[] = {
    PUSH, 5,
    PUSH, 6,
    ADD,
    POP,
    HALT
};

// Instruction pointer
int ip = 0;

// Stack pointer,
// Initialized to -1 here, since sp is increased before the value is pushed onto the stack
int sp = -1;

// Dah stack!
int stack[256];

// fetch next instruction to execute
int fetch() {
    return instruction[ip];
}

bool running = true;

void execute(int instr) {
    switch (instr) {
        case PUSH: {
            stack[++sp] = instruction[++ip];
            break;
        }
        case POP: {
            // store the value at the top of the stack in `val_popped`
            // then decrease the stack pointer
            // and finally, print out the result (only for debugging purpose)
            int val_popped = stack[sp--];
            printf("just popped %d\n", val_popped);
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
        case HALT: {
            running = false;
            break;
        }
    }
}

int main() {
    while (running) {
        execute(fetch());
        ip++; // increment the ip every iteration
    }
}
