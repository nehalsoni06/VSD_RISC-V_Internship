# VSD RISC-V FPGA based Internship

---

**Submitted by:** Nehal Soni

**Roll Number:** 24UEC191

**Email ID:** [nehalsoni06@gmail.com](mailto:nehalsoni06@gmail.com)

## Overview

### Task 1: Software Modelling and Verification Using GCC and RISC-V Toolchains

This task focuses on understanding software modelling and functional verification using a simple C program. The program is compiled and executed using both the native GCC compiler and the RISC-V GCC cross-compiler. The objective is to verify that the same functionality is preserved across different architectures and to gain familiarity with the RISC-V software development workflow.

### Task 2: Spike Debugging and Verification of a Ring Counter Program Using GCC and RISC-V Compiler

This task focuses on understanding program execution using Spike Simulator and debugging RISC-V binaries at the instruction level. A Ring Counter software model is then compiled using both GCC and the RISC-V GCC compiler to verify functionality across architectures. The task provides practical exposure to simulation, debugging, and verification methodologies used in embedded systems, processor design, and VLSI development.

### Task 3: FPGA Development Environment Setup and Build Flow

This task focuses on setting up the FPGA development environment required for implementing a RISC-V design using open-source FPGA tools. The repository is cloned, dependencies are installed, and the FPGA toolchain consisting of Yosys, NextPNR, IceStorm, and GTKWave is configured and verified.

The task also introduces the FPGA build and flashing workflow using the provided Makefile. Due to the hardware access limitations of GitHub Codespaces, the setup and verification were performed in a Linux Virtual Machine environment to enable direct communication with the FPGA board through USB.


## Task 4: GPIO IP Design and SoC Integration

This task focuses on designing and integrating a simple GPIO IP core into a RISC-V based SoC system.

### Objective
To design, integrate, and verify a GPIO IP module accessible by the RISC-V CPU through a memory-mapped interface.

### Work Done
- Designed a simple GPIO IP RTL module  
- Defined memory-mapped address space for GPIO access  
- Integrated GPIO IP into the RISC-V SoC design  
- Connected GPIO signals to external interface for testing  
- Updated SoC interconnect for peripheral access  

### CPU Interaction
- The RISC-V CPU accesses GPIO using load/store instructions  
- Memory-mapped I/O is used for reading and writing GPIO registers  
- Address decoding logic routes CPU requests to the GPIO IP  

### Verification
- Functional simulation performed for read/write validation  
- Waveforms analyzed using GTKWave  
- GPIO behavior verified through test stimulus  
- (Optional) UART/log output used for runtime verification  

### Outcome
- Understood memory-mapped peripheral architecture  
- Learned CPU-to-IP communication in SoC design  
- Gained practical experience in RTL integration and verification  
- Verified correct GPIO functionality through simulation  

---

## Notes

- Screenshots (simulation waveforms, RTL snapshots, FPGA build logs) can be added under each task section  
- All tasks were verified using simulation and/or Linux-based development environments  
- This project follows an open-source RISC-V hardware–software co-design workflow  

