# COP3402-Project1
## COP3402 Systems Software Project 1 with
## David Qualls, Jenna Busch, and Kyle Mauter

==============================================

# Assignment Instructions
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

The Instruction Set Architecture of the P-machine is as follows:
  There are three fields "OP L M" that are separated by a single space character
  - OP: operation code, specifies the instruction to execute
  - R: register, specifies which register the operation should output in or store from
  - L: lexicographical level
  - M: depends on the operator it indicates
      * A number          (instructions: LIT, INC)
      * A program address (instructions: JMP, JPC, CAL)
      * A data address    (instructions: LOD, STO)
