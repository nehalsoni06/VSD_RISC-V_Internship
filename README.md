# Task 1: Understanding Software Modelling, Compilation, and Verification Using GCC and RISC-V Toolchains

## Overview

In digital system design, hardware is rarely developed directly from an idea. The functionality of a system is first described and verified using software models before being translated into hardware. This approach helps identify and eliminate functional errors early in the design cycle, reducing development time and cost.

The objective of this task is to understand this fundamental concept by creating a software model in C, compiling it using both the native GCC compiler and the RISC-V cross-compiler, and comparing the outputs. A Fibonacci Series program is used as a simple example to demonstrate the workflow.

---

## Theory

### Software Modelling in Digital Design

Before implementing a design in hardware, its functionality is represented using a high-level software model. This model serves as a reference specification that describes the expected behavior of the system.

The software model is verified through simulation and testing before proceeding to hardware design.

```text
Specification Model (C Program)
            ↓
      Verification
            ↓
      RTL Design
            ↓
      Hardware
```

This methodology ensures that the functionality is validated before moving to more complex stages of implementation.

---

### Chip Modelling and Verification

Chip modelling begins with a specification written in a high-level language such as C. The specification acts as a reference model against which future implementations can be verified.

A testbench is used to provide inputs and observe outputs.

```text
Specification Model
         ↓
     Testbench
         ↓
 Functional Verification
```

The purpose of verification is to ensure that the system behaves exactly as intended.

---

### RTL Design

After validating the software model, the design is represented in RTL (Register Transfer Level) using hardware description languages such as Verilog.

```text
C Specification
       ↓
RTL Model
       ↓
Hardware Implementation
```

The RTL model should produce results identical to those produced by the specification model.

---

### RISC-V Toolchain

RISC-V is an open-standard Instruction Set Architecture (ISA) used for processor design and embedded systems development.

The RISC-V toolchain allows software to be compiled and tested for RISC-V processors without requiring physical hardware.

Components used in this task:

* GCC Compiler
* RISC-V GCC Cross Compiler
* Spike Simulator

---

## Task Objective

The purpose of this task is to:

* Understand software modelling concepts.
* Learn the compilation process.
* Explore cross-compilation for RISC-V architecture.
* Verify functionality across different architectures.
* Gain familiarity with the RISC-V development workflow.

---

## Example Program: Fibonacci Series

To demonstrate the concepts discussed above, a simple Fibonacci Series program is used.

The Fibonacci sequence is a mathematical sequence where each term is the sum of the previous two terms.

### Sequence

```text
0 1 1 2 3 5 8 13 ...
```

### Source Code

```c
#include <stdio.h>

int main() {
    int n = 4, a = 0, b = 1, c;

    printf("Fibonacci Series: ");

    for(int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}
```

---

## Compiling and Running with GCC

The first step is to compile and execute the program using the native GCC compiler.

### Commands

```bash
gcc fibonacci.c
./a.out
```

### Output

```text
Fibonacci Series: 0 1 1 2
```

### Screenshot

> Insert GCC compilation and output screenshot here.

---

## Modifying the Program

To observe changes in program behavior, the value of `n` is modified from `4` to `6`.

### Editing the Source Code

```bash
gedit fibonacci.c
```

### Modification

```c
int n = 6;
```

### Recompile and Execute

```bash
gcc fibonacci.c
./a.out
```

### Output

```text
Fibonacci Series: 0 1 1 2 3 5
```

### Screenshot

> Insert modified code and output screenshot here.

---

## Cross Compilation Using RISC-V

The same program is now compiled for the RISC-V architecture.

### Compilation

```bash
riscv64-unknown-elf-gcc -o fibonacci.o fibonacci.c
```

### Execution Using Spike

```bash
spike pk fibonacci.o
```

### Output

```text
Fibonacci Series: 0 1 1 2 3 5
```

### Screenshot

> Insert RISC-V compilation and execution screenshot here.

---

## Understanding What Happened

Although the same source code was used throughout the task, two different compilers generated machine code for two different architectures.

### GCC Flow

```text
C Program
    ↓
 GCC Compiler
    ↓
x86 Machine Code
    ↓
Execution
```

### RISC-V Flow

```text
C Program
    ↓
RISC-V Compiler
    ↓
RISC-V Machine Code
    ↓
Spike Simulator
    ↓
Execution
```

Even though the generated machine instructions are different, the functionality remains the same.

This demonstrates one of the most important principles of software modelling:

> A specification should remain functionally correct regardless of the target architecture.

---

## Observations

* The Fibonacci program compiled successfully using both GCC and RISC-V compilers.
* Changing the value of `n` produced the expected increase in sequence length.
* Both toolchains generated identical outputs.
* Spike successfully simulated execution of the RISC-V binary.
* The functionality of the program remained unchanged across architectures.
* The experiment demonstrated how a software model can be verified before moving towards hardware implementation.

---

## Key Learnings

* Understanding software modelling in digital design.
* Importance of verification before hardware implementation.
* Basics of GCC compilation.
* Cross-compilation using the RISC-V toolchain.
* Execution of RISC-V binaries using Spike.
* Relationship between software models and hardware design.
* Functional equivalence across different architectures.

---

## Conclusion

This task introduced the fundamental workflow used in digital system design: modelling, compilation, verification, and validation.

Using a Fibonacci Series program as a software model, the program was compiled and executed using both GCC and the RISC-V toolchain. The outputs obtained from both environments were identical, confirming that the functionality of the specification remained unchanged across architectures.

The task provided practical exposure to software modelling, cross-compilation, and simulation while demonstrating how functionality is verified before progressing towards hardware implementation. These concepts form the foundation of processor design, digital VLSI development, and the broader System-on-Chip (SoC) design flow.
