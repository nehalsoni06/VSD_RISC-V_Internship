# Task 2: Spike Debugging and Verification of a Ring Counter Program Using GCC and RISC-V Compiler

## Table of Contents

- [Overview](#overview)
- [Part 1: Spike Simulation and Debugging](#part-1-spike-simulation-and-debugging)
  - [Objective](#objective)
  - [Program Used for Debugging](#program-used-for-debugging)
  - [Compilation for RISC-V](#compilation-for-risc-v)
  - [Running on Spike Simulator](#running-on-spike-simulator)
  - [Spike Debug Mode](#spike-debug-mode)
  - [Common Debug Commands](#common-debug-commands)
  - [Observations from Debugging](#observations-from-debugging)
- [Part 2: Verification of a Ring Counter Program Using GCC and RISC-V Compiler](#part-2-verification-of-a-ring-counter-program-using-gcc-and-risc-v-compiler)
  - [Objective](#objective-1)
  - [Theory](#theory)
  - [Program Used for Verification](#program-used-for-verification)
  - [Compilation Using GCC](#compilation-using-gcc)
  - [Cross Compilation Using RISC-V GCC](#cross-compilation-using-risc-v-gcc)
  - [Executing on Spike Simulator](#executing-on-spike-simulator)
  - [Verification Results](#verification-results)
  - [Understanding the Workflow](#understanding-the-workflow)
  - [Toolchain Analysis](#toolchain-analysis)
  - [Observations](#observations)
  - [Key Learnings](#key-learnings)
  - [Conclusion](#conclusion)

---

## Overview

Software models are commonly used as reference specifications before hardware implementation. These models are verified and analyzed to ensure correct functionality. In this task, Spike Simulator is used to understand RISC-V program execution and debugging, followed by verification of a Ring Counter program using both GCC and the RISC-V GCC compiler.

---

# Part 1: Spike Simulation and Debugging

## Objective

- Understand Spike Simulator and its debugging capabilities.
- Analyze program execution at the instruction level.
- Inspect register values during execution.
- Understand how software executes on a RISC-V processor.

---

## Program Used for Debugging

### Source Code (`sum1ton.c`)

```c
#include <stdio.h>

int main(){

    int i, sum = 0, n = 15;

    for(i = 1; i <= n; i++)
        sum += i;

    printf("Sum from 1 to %d is %d\n", n, sum);

    return 0;
}
```

### Expected Output

```text
Sum from 1 to 15 is 120
```

---

## Compilation for RISC-V

```bash
riscv64-unknown-elf-gcc -o sum1ton.o sum1ton.c
```

---

## Running on Spike Simulator

```bash
spike pk sum1ton.o
```

### Output

```text
Sum from 1 to 15 is 120
```

## Spike Debug Mode

To analyze program execution step-by-step:

```bash
spike -d pk sum1ton.o
```

The simulator enters interactive debug mode.

### Screenshot(Spike execution and Debud mode)

![spike execution and Debug Mode](screenshots/Screenshot\(90\).png)

---

## Common Debug Commands

### Display Current Program Counter

```text
pc
```

### Display Register Value

```text
reg 0 a0
```

### Execute One Instruction

```text
run 1
```

### Continue Execution

```text
c
```

### Quit Debugger

```text
q
```
### Screenshot(main file)

![main file](screenshots/Screenshot\(83\).png)

---
### Screenshot( commands debug observations)

![spike execution and Debug Mode](screenshots/Screenshot\(91\).png)
![spike execution and Debug Mode](screenshots/Screenshot\(92\).png)

---

## Observations from Debugging

- Instructions are executed sequentially.
- Register values change during execution.
- The Program Counter (PC) updates after every instruction.
- Spike enables instruction-level visibility of program behavior.
- Debugging helps verify correct execution before hardware deployment.

---

# Part 2: Verification of a Ring Counter Program Using GCC and RISC-V Compiler

## Objective

The goal of this section is to verify that a Ring Counter software model produces identical functionality when compiled using both GCC and the RISC-V GCC compiler.

---

## Theory

A Ring Counter is a sequential digital circuit formed using a shift register where the output of the last flip-flop is connected back to the input of the first flip-flop.

A single logic '1' circulates through the register positions, producing a repeating sequence of states.

```text
1000
↓
0100
↓
0010
↓
0001
↓
1000
```

Ring Counters are commonly used in:

- Sequence generators
- Timing circuits
- Control units
- Digital system synchronization

---

## Program Used for Verification

### Source Code (`ring_counter.c`)

```c
#include <stdio.h>

int main() {

    int ring[4] = {1, 0, 0, 0};

    printf("Ring Counter Sequence:\n");

    for(int i = 0; i < 8; i++) {

        printf("%d%d%d%d\n",
               ring[0], ring[1],
               ring[2], ring[3]);

        int temp = ring[3];

        ring[3] = ring[2];
        ring[2] = ring[1];
        ring[1] = ring[0];
        ring[0] = temp;
    }

    return 0;
}
```

### Expected Output

```text
Ring Counter Sequence:

1000
0100
0010
0001
1000
0100
0010
0001
```

The program models the behavior of a 4-bit Ring Counter and serves as the software specification for verification.

---

## Compilation Using GCC

Compile the program using the native GCC compiler.

```bash
gcc ring_counter.c
./a.out
```

### Output

```text
Ring Counter Sequence:

1000
0100
0010
0001
1000
0100
0010
0001
```

### Screenshot

> Add GCC compilation screenshot here.

---

## Cross Compilation Using RISC-V GCC

Compile the same program for the RISC-V architecture.

```bash
riscv64-unknown-elf-gcc -o ring_counter.o ring_counter.c
```

### Screenshot

> Add RISC-V compilation screenshot here.

---

## Executing on Spike Simulator

Run the generated RISC-V executable.

```bash
spike pk ring_counter.o
```

### Output

```text
Ring Counter Sequence:

1000
0100
0010
0001
1000
0100
0010
0001
```

### Screenshot

> Add Spike execution screenshot here.

---

## Verification Results

| Compiler | Result |
|-----------|----------|
| GCC | Ring Counter Sequence Generated Successfully |
| RISC-V GCC + Spike | Ring Counter Sequence Generated Successfully |

Since both outputs are identical, the functionality of the Ring Counter model is successfully verified.

---

## Understanding the Workflow

```text
Ring Counter C Program
            ↓
      GCC Compiler
            ↓
      Native Output

Ring Counter C Program
            ↓
   RISC-V GCC Compiler
            ↓
      Spike Simulator
            ↓
      RISC-V Output

Native Output = RISC-V Output
```

---

## Toolchain Analysis

### GCC Compiler

- Compiles programs for the host machine.
- Used for native execution and verification.

### RISC-V GCC Compiler

- Cross-compiles programs for the RISC-V architecture.
- Generates RISC-V machine code.

### Spike Simulator

- Executes RISC-V binaries.
- Supports simulation and debugging.
- Useful for verification without hardware.

---

## Observations

- The `sum1ton.c` program executed successfully in Spike Simulator.
- Spike debug mode enabled instruction-by-instruction execution analysis.
- Register values and program flow could be observed during runtime.
- The Ring Counter program compiled successfully using both GCC and RISC-V GCC.
- GCC and RISC-V GCC generated functionally equivalent executables.
- Spike successfully executed the RISC-V binary.
- The Ring Counter sequence remained identical across architectures.
- Verification confirmed correct functionality of the software model.

---

## Key Learnings

- Spike simulation and debugging.
- Register-level program analysis.
- GCC compilation workflow.
- RISC-V cross-compilation.
- Digital system modelling.
- Software verification techniques.
- Architecture-independent functionality.

---

## Conclusion

This task demonstrated two important aspects of the RISC-V software development workflow. In the first part, Spike Simulator was used to debug and analyze the execution of the `sum1ton.c` program at the instruction level. Register values, program flow, and execution behavior were observed using Spike's interactive debugging environment.

In the second part, a Ring Counter software model was compiled using both GCC and the RISC-V GCC compiler. The outputs obtained from both environments were identical, confirming correct functionality and successful verification of the software model. Together, these exercises provided practical exposure to simulation, debugging, and verification methodologies commonly used in processor design, embedded systems development, and VLSI workflows.
