# COP3402-Project1
## COP3402 Systems Software Project 1 with:
###  - David Qualls
###  - Jenna Bush
###  - Kyle Mauter

In this assignment we'll be implementing a virtual machine called the P-machine. 

The P-machine has two memory areas:
  - Stack: stores variables and grows downwards
  - Text:  stores instructions for VM to execute

Also has register file where arithmetic and logic instructions are executed
The P-machine has registers to handle the stack:
  - BP: Base Pointer
  - SP: Stack Pointer
  - PC: Program Counter
  - IR: Instruction Register

