# Minimum functionality

step 1: basic operations + interpreter + multi programming
step 2: io operations
step 3: in-vm networking

## Instructions:

### Branch instructions

These instructions are used to:

- branch backwards to form loops
- branch forward in conditional structures
- branch to subroutines
- change the processor from ARM state to Thumb state.

### Data processing instructions

These instructions operate on the general-purpose registers. They can perform operations such as addition, subtraction, or bitwise logic on the contents of two registers and place the result in a third register. They can also operate on the value in a single register, or on a value in a register and a constant supplied within the instruction (an immediate value).

Long multiply instructions (unavailable in some architectures) give a 64-bit result in two registers.

### Single register load and store instructions

These instructions load or store the value of a single register from or to memory. They can load or store a 32-bit word or an 8-bit unsigned byte. In ARM architecture v4 and above they can also load or store a 16-bit unsigned halfword, or load and sign extend a 16-bit halfword or an 8-bit byte.
Multiple register load and store instructions

These instructions load or store any subset of the general-purpose registers from or to memory. Refer to Load and store multiple register instructions for a detailed description of these instructions.
Status register access instructions

These instructions move the contents of the CPSR or an SPSR to or from a general-purpose register.

### Semaphore instructions

These instructions load and alter a memory semaphore.

### Coprocessor instructions

These instructions support a general way to extend the ARM architecture.
