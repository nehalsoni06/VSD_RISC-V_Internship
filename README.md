# Task 1: Software Modelling and Verification Using GCC and RISC-V Toolchains

## Overview

Digital system design begins with creating a software model that describes the intended functionality of a system. Before moving to hardware implementation, this model is verified to ensure correct behavior. This approach helps identify functional errors early in the design process and forms the foundation of modern VLSI and SoC design methodologies.

In this task, a simple C program is used to demonstrate software modelling, compilation, verification, and cross-compilation using both the native GCC compiler and the RISC-V toolchain.

---

## Theory

### Software Modelling

A software model acts as a reference specification for the desired functionality of a system. The model is verified before proceeding to hardware implementation.

```text
Specification Model (C Program)
            ↓
      Verification
            ↓
        RTL Design
            ↓
      Hardware Design
```

The purpose of verification is to ensure that the design behaves exactly as intended before additional complexity is introduced.

---

### Chip Modelling and Verification

The functionality of a design is first represented using a high-level programming language such as C. This model is then tested using different inputs to verify its correctness.

```text
Specification Model
         ↓
     Testbench
         ↓
 Functional Verification
```

Once the functionality is verified, the same behavior can be implemented in hardware using RTL.

---

### RISC-V Toolchain

RISC-V is an open-source Instruction Set Architecture (ISA) widely used in processor and embedded system design.

The RISC-V toolchain enables developers to:

* Compile software for the RISC-V architecture.
* Simulate execution without physical hardware.
* Verify functionality across different architectures.

Tools used in this task:

* GCC Compiler
* RISC-V GCC Cross Compiler
* Spike Simulator

---

## Objective

The objective of this task is to:

* Understand software modelling concepts.
* Learn the compilation process.
* Explore cross-compilation for RISC-V.
* Verify program functionality across architectures.
* Gain hands-on experience with the RISC-V development workflow.

---

## Program Used for Analysis

To demonstrate the workflow, a simple C program is used to calculate the sum of natural numbers from 1 to N.

### Source Code

```c
#include <stdio.h>

int main(){

  int i, sum=0, n=9;

  for(i=1;i<=n;i++)
    sum = sum + i;

  printf("Sum from 1 to %d is %d\n",n,sum);

  return 0;

}
```

### Expected Result

For N = 9:

```text
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
```

This example includes:

* Variable initialization
* Arithmetic operations
* Loop execution
* Output generation

making it suitable for understanding compilation and verification workflows.

---

# Compilation and Execution Using GCC

The program is first compiled and executed using the native GCC compiler.

### Commands

```bash
gcc sum1ton.c
./a.out
```

### Output

```text
Sum from 1 to 9 is 45
```

### Screenshot

![GCC Output](screenshots/Screenshot(66).png)

---

# Modifying the Program

To observe the effect of changing program inputs, the value of `n` is modified from **9** to **19**.

### Editing the Source File

```bash
gedit sum1ton.c
```

### Modification

```c
int i, sum = 0, n = 19;
```

### Recompile and Execute

```bash
gcc sum1ton.c
./a.out
```

### Output

```text
Sum from 1 to 19 is 190
```

### Screenshot

> Add screenshot showing code modification and updated output here.

---

# Cross Compilation Using RISC-V

The same source code is compiled for the RISC-V architecture using the RISC-V GCC cross-compiler.

### Compilation

```bash
riscv64-unknown-elf-gcc -o sum1ton.o sum1ton.c
```

### Execution Using Spike Simulator

```bash
spike pk sum1ton.o
```

### Output

```text
Sum from 1 to 19 is 190
```

### Screenshot

> Add screenshot of RISC-V compilation and Spike execution here.

---

# Understanding the Workflow

The complete workflow followed during this task is shown below:

```text
C Program
    ↓
Compiler
(GCC / RISC-V GCC)
    ↓
Machine Code
    ↓
Execution
(Native System / Spike Simulator)
    ↓
Output Verification
```

Although different machine instructions are generated for different architectures, the functionality of the program remains unchanged.

---

# Toolchain Analysis

## GCC Compiler

* Produces machine code for the host architecture.
* Used for native software development.
* Allows quick verification of program functionality.

## RISC-V GCC Compiler

* Cross-compiles source code for the RISC-V ISA.
* Generates architecture-specific machine instructions.
* Enables software development for RISC-V processors.

## Spike Simulator

* Reference simulator for the RISC-V ISA.
* Executes RISC-V binaries without requiring physical hardware.
* Useful for testing and verification during development.

---

# Observations

* The program compiled and executed successfully using both GCC and the RISC-V toolchain.
* Modifying the value of `n` changed the output as expected.
* Both compilation environments produced identical results.
* Spike successfully simulated the execution of the RISC-V binary.
* Program functionality remained consistent across architectures.

---

# Key Learnings

* Understanding software modelling and verification.
* Compiling C programs using GCC.
* Editing source files using Gedit.
* Cross-compilation using the RISC-V toolchain.
* Executing RISC-V binaries using Spike.
* Verifying software functionality before hardware implementation.
* Understanding architecture-independent program behavior.

---

# Conclusion

This task introduced the fundamental concepts of software modelling, compilation, and verification used in digital system design. A simple C program was used as a specification model and executed using both GCC and the RISC-V toolchain.

The outputs obtained from both environments were identical, demonstrating that the functionality of the program remained unchanged despite targeting different architectures. This exercise provided practical exposure to the RISC-V development workflow and highlighted the importance of verification before moving toward hardware implementation.
