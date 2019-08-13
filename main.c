// The virtual machine is based on stack
// I think "stack machine" might not be a bad idea :)

// We will have A, B, C, D, E and F, 6 registers in total for the virtual machine

// Instruction set for the virtual machine:
// PSH 5       ; pushes 5 to the stack
// PSH 10      ; pushes 10 to the stack
// ADD         ; pops two values on top of the stack, adds them pushes to stack
// POP         ; pops the value on the stack, will also print it for debugging
// SET A 0     ; sets register A to 0
// HLT         ; stop the program
