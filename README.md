# Task 1: Software Modelling and Verification Using GCC and RISC-V Toolchains

## Overview

Digital system design begins with creating a software model that describes the intended functionality of a system. Before moving to hardware implementation, this model is verified to ensure correct behavior. This approach helps identify functional errors early in the design process and forms the foundation of modern VLSI and SoC design methodologies.

In this task, a simple C program is used to demonstrate software modelling, compilation, verification, optimization, disassembly, and cross-compilation using both the native GCC compiler and the RISC-V toolchain.

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
* Analyze generated machine instructions.
* Verify functionality across different architectures.

Tools used in this task:

* GCC Compiler
* RISC-V GCC Cross Compiler
* Object Dump Utility
* Spike Simulator

---

## Objective

The objective of this task is to:

* Understand software modelling and verification concepts.
* Learn the compilation and execution workflow.
* Explore cross-compilation for the RISC-V architecture.
* Understand compiler optimization using `-O1` and `-Ofast`.
* Analyze RISC-V instructions through disassembly.
* Verify program functionality across different architectures.
* Gain hands-on experience with the RISC-V development toolchain.

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

![Original C code](screenshots/Screenshot\(68\).png)

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

![GCC Output](screenshots/Screenshot\(66\).png)

---

# Modifying the Program

To observe the effect of changing program inputs, the value of `n` is modified.

### Editing the Source File

```bash
gedit sum1ton.c
```

![gedit](screenshots/Screenshot\(67\).png)

### Modification

```c
int i, sum = 0, n = 15;
```

### Recompile and Execute

```bash
gcc sum1ton.c
./a.out
```

### Output

```text
Sum from 1 to 15 is 120
```

### Screenshot

![Changed code](screenshots/Screenshot\(69\).png)

![Changed Output](screenshots/Screenshot\(70\).png)

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
Sum from 1 to 15 is 120
```

### Screenshot

![RISC-V GCC Output](screenshots/Screenshot\(71\).png)

---

# Compiler Optimization

Compiler optimizations improve the efficiency of the generated machine code while preserving the functionality of the program.

## O1 Optimization

The program was compiled using the `-O1` optimization flag:

```bash
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton_O1.o sum1ton.c
```

The `-O1` optimization level performs basic optimizations such as:

* Removing redundant instructions
* Improving execution efficiency
* Reducing code size
* Maintaining program correctness

### Screenshot

![O1 Optimization](screenshots/Screenshot\(78\).png)

---

## Ofast Optimization

The program was also compiled using the `-Ofast` optimization flag:

```bash
riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton_fast.o sum1ton.c
```

`-Ofast` enables aggressive compiler optimizations aimed at maximizing performance.

Benefits include:

* Faster execution
* More efficient instruction scheduling
* Reduced execution overhead
* Better runtime performance

### Screenshot

![Ofast Optimization](screenshots/Screenshot\(82\).png)

---

# Disassembly and Instruction Analysis

After compilation, the generated object file was disassembled to observe the RISC-V instructions produced by the compiler.

## Commands

```bash
riscv64-unknown-elf-objdump -d sum1ton_O1.o
```

For easier navigation through large outputs:

```bash
riscv64-unknown-elf-objdump -d sum1ton_O1.o | less
```

### Useful Commands Inside Less

| Command | Function                 |
| ------- | ------------------------ |
| Space   | Next page                |
| b       | Previous page            |
| /main   | Search for main function |
| n       | Next occurrence          |
| q       | Quit                     |

### Screenshot

#### For O1
![disassembly for O1](screenshots/Screenshot\(79\).png)
![main for O1](screenshots/Screenshot\(81\).png)

#### For Ofast
![disassembly Output for Ofast](screenshots/Screenshot\(83\).png)
![main for Ofast](screenshots/Screenshot\(87\).png)


---

## Common RISC-V Instructions Observed

| Instruction | Description                            |
| ----------- | -------------------------------------- |
| addi        | Add Immediate                          |
| auipc       | Add Upper Immediate to Program Counter |
| jal         | Jump and Link                          |
| ret         | Return from Function                   |
| li          | Load Immediate                         |
| sub         | Subtract                               |
| beqz        | Branch if Equal to Zero                |
| bnez        | Branch if Not Equal to Zero            |

These instructions collectively implement the logic originally written in C.

---

# Comparing Optimization Levels

Generate disassembly files:

```bash
riscv64-unknown-elf-objdump -d sum1ton_O1.o > O1.txt

riscv64-unknown-elf-objdump -d sum1ton_fast.o > Ofast.txt
```

Compare both outputs:

```bash
diff O1.txt Ofast.txt
```

or

```bash
vimdiff O1.txt Ofast.txt
```

### Observation

* Both optimization levels maintain functional correctness.
* `-Ofast` generates more aggressively optimized machine code.
* Different optimization levels affect implementation efficiency rather than functionality.
* Disassembly helps visualize the impact of compiler optimizations on generated instructions.

---

# Understanding the Workflow

The complete workflow followed during this task is shown below:

```text
C Source Code
       ↓
Compilation
(GCC / RISC-V GCC)
       ↓
Optimization
(-O1 / -Ofast)
       ↓
Object File Generation
       ↓
Disassembly
(objdump)
       ↓
RISC-V Instructions
       ↓
Execution
(Spike Simulator)
       ↓
Output Verification
```

This workflow demonstrates how a high-level C program is transformed into machine-executable instructions and verified before hardware implementation.

---

# Toolchain Analysis

## GCC Compiler

* Compiles C programs for the host machine.
* Generates executable machine code.
* Used for functional verification of the software model.

## RISC-V GCC Compiler

* Cross-compiles C programs for the RISC-V architecture.
* Generates RISC-V specific machine instructions.
* Supports optimization levels such as `-O1` and `-Ofast`.

## Object Dump Utility

* Disassembles compiled binaries into assembly code.
* Helps analyze compiler-generated instructions.
* Used to study instruction-level implementation.

## Spike Simulator

* Reference simulator for the RISC-V ISA.
* Executes RISC-V binaries without physical hardware.
* Used for testing and verification of RISC-V programs.

---

# Observations

* The program compiled and executed successfully using both GCC and the RISC-V toolchain.
* Modifying the value of `n` changed the output as expected.
* Both compilation environments produced identical results.
* Spike successfully simulated the execution of the RISC-V binary.
* Program functionality remained consistent across architectures.
* Compiler optimization flags (`-O1` and `-Ofast`) generated different assembly implementations while preserving functionality.
* Disassembly revealed how high-level C code is translated into RISC-V instructions.
* The `less` utility simplified navigation through large disassembly outputs.
* Disassembly comparison highlighted differences between optimization levels.
* Higher optimization levels improved code efficiency without changing the output.

---

# Key Learnings

* Understanding software modelling and verification.
* Compiling C programs using GCC.
* Cross-compiling programs for the RISC-V architecture.
* Executing RISC-V binaries using Spike Simulator.
* Exploring compiler optimization using `-O1` and `-Ofast`.
* Understanding disassembly and instruction analysis.
* Learning how C code is translated into RISC-V instructions.
* Verifying functionality across different architectures.
* Gaining exposure to the RISC-V development workflow.

---

# Conclusion

This task introduced the fundamental concepts of software modelling, compilation, optimization, and verification used in digital system design. A simple C program was used as a specification model and executed using both GCC and the RISC-V toolchain.

The outputs obtained from both environments were identical, demonstrating that the functionality of the program remained unchanged despite targeting different architectures. Compiler optimizations using `-O1` and `-Ofast` further demonstrated how performance can be improved without affecting correctness.

The task also provided an introduction to disassembly and instruction-level analysis, showing how high-level C code is translated into RISC-V machine instructions. Overall, this exercise provided practical exposure to the software development and verification workflow used in modern processor and VLSI design.
