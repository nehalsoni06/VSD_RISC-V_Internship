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

Software modelling and verification are essential steps in the digital design workflow. Before implementing a design in hardware, its functionality is first represented and tested using software models. This helps identify errors early and ensures that the intended behavior is preserved throughout the design process.

In this task, Spike Simulator is used to explore the execution and debugging of RISC-V programs at the instruction level. Additionally, a Ring Counter software model is compiled and verified using both the native GCC compiler and the RISC-V GCC toolchain to demonstrate architecture-independent functionality.

---

# Part 1: Spike Simulation and Debugging

## Objective

- Understand the role of Spike Simulator in RISC-V development.
- Learn instruction-level debugging and program analysis.
- Observe register and program counter behavior during execution.
- Gain practical experience with RISC-V software debugging.

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

### Screenshot

![Spike Execution](screenshots/Screenshot\(90\).png)

---

## Spike Debug Mode

To analyze program execution step-by-step:

```bash
spike -d pk sum1ton.o
```

The simulator enters interactive debug mode.

### Screenshot

![Main File](screenshots/Screenshot\(83\).png)

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

### Debug Observation Screenshots

![Debug Observation 1](screenshots/Screenshot\(91\).png)

![Debug Observation 2](screenshots/Screenshot\(92\).png)

---

## Observations from Debugging

- Spike Simulator successfully executed the compiled RISC-V program.
- Instructions were executed sequentially and could be analyzed individually.
- Register values changed according to program execution.
- The Program Counter (PC) advanced after each instruction.
- Debug mode provided a deeper understanding of how software interacts with processor hardware.

---

# Part 2: Verification of a Ring Counter Program Using GCC and RISC-V Compiler

## Objective

The objective of this section is to verify the functionality of a Ring Counter software model using both GCC and the RISC-V GCC compiler. By comparing the outputs generated on different architectures, we can confirm the correctness and portability of the software model.

---

## Theory

A Ring Counter is a sequential digital circuit formed using a shift register where the output of the last stage is connected back to the input of the first stage.

A single logic '1' continuously circulates through the register positions, creating a repeating sequence of states.

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

### Applications

- Sequence generators
- Timing circuits
- Control units
- Digital synchronization systems

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

### Screenshot

![Ring Counter Code](screenshots/Screenshot\(94\).png)

---

## Compilation Using GCC

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

![GCC Output](screenshots/Screenshot\(95\).png)

---

## Cross Compilation Using RISC-V GCC

```bash
riscv64-unknown-elf-gcc -o ring_counter.o ring_counter.c
```

---

## Executing on Spike Simulator

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

![RISC-V Compilation and Execution](screenshots/Screenshot\(96\).png)

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
- Enables verification without physical hardware.

---

## Observations

- The `sum1ton.c` program executed correctly in Spike Simulator.
- Debug mode enabled detailed analysis of instruction execution and register activity.
- The Ring Counter program compiled successfully using both GCC and RISC-V GCC.
- Identical outputs were obtained from both compilation environments.
- The functionality of the software model remained unchanged across architectures.
- Spike Simulator provided an effective platform for testing and verification without requiring physical hardware.
- The experiment demonstrated the importance of software verification before hardware implementation.

---

## Key Learnings

- Understanding software modelling and verification concepts.
- Learning RISC-V simulation and debugging using Spike.
- Analyzing program execution at the instruction level.
- Compiling programs using GCC and RISC-V GCC.
- Verifying software functionality across different architectures.
- Understanding the role of software verification in digital design workflows.

---

## Conclusion

This task provided practical exposure to the software development and verification flow used in modern digital design and embedded systems. Through Spike Simulator, the execution of a RISC-V program was analyzed at the instruction level, offering insight into processor behavior, register operations, and program flow.

The Ring Counter software model was then compiled and executed using both GCC and the RISC-V GCC toolchain. The identical outputs obtained from both environments confirmed the correctness and portability of the design. Overall, this task highlighted the importance of simulation, debugging, and verification as foundational steps before moving toward hardware implementation.
