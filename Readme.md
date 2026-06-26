# VSD RISC-V FPGA based Internship

---

**Submitted by:** Nehal Soni

**Roll Number:** 24UEC191

**Email ID:** [nehalsoni06@gmail.com](mailto:nehalsoni06@gmail.com)

## Overview

### Task 1: Software Modelling and Verification Using GCC and RISC-V Toolchains

This task focuses on understanding software modelling and functional verification using a simple C program. The program is compiled and executed using both the native GCC compiler and the RISC-V GCC cross-compiler to verify consistent functionality across different architectures. The objective is to gain familiarity with the RISC-V software development workflow and cross-compilation process.

---

### Task 2: Spike Debugging and Verification of a Ring Counter Program Using GCC and RISC-V Compiler

This task focuses on debugging RISC-V programs using the Spike Simulator. A Ring Counter software model is compiled using both GCC and the RISC-V GCC compiler, and its execution is analyzed at the instruction level. The objective is to understand processor execution, debugging techniques, and software verification methodologies used in embedded systems and VLSI design.

---

### Task 3: FPGA Development Environment Setup and Build Flow

This task focuses on setting up the complete open-source FPGA development environment required for implementing a RISC-V design. The FPGA toolchain, including Yosys, NextPNR, IceStorm, and GTKWave, is installed and verified. The complete FPGA build, synthesis, place-and-route, and flashing workflow is explored using the provided Makefile, with validation performed in a Linux Virtual Machine due to GitHub Codespaces hardware limitations.

---

### Task 4: GPIO IP Design and SoC Integration

This task focuses on designing and integrating a custom GPIO IP core into a RISC-V based System-on-Chip. The GPIO peripheral is connected through a memory-mapped interface, allowing the CPU to access it using standard load and store instructions. Functional simulation and waveform analysis are performed to verify correct peripheral operation and CPU-to-IP communication.

---

### Task 5: Multi-Register GPIO IP with Software Control

This task extends the basic GPIO peripheral into a fully software-controlled multi-register IP core. A register map consisting of GPIO_DATA, GPIO_DIR, and GPIO_READ is implemented to support configurable GPIO direction, data output, and input readback. The enhanced IP is integrated into the RISC-V SoC, verified through IP-level and SoC-level simulations, controlled using a C program executed on the RISC-V processor, and finally synthesized, implemented, and validated on the VSDSquadron iCE40 FPGA board.
