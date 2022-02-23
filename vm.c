/*
	You can use these two print statements for the errors:
		printf("Virtual Machine Error: Stack Overflow Error\n");
		printf("Virtual Machine Error: Out of Bounds Access Error\n");
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"
#define REG_FILE_SIZE 10
#define MAX_STACK_LENGTH 100

/* From the header file

	typedef struct instruction {
		int opcode;
		int r;
		int l;
		int m;
	} instruction;

*/

void print_execution(int line, char *opname, instruction IR, int PC, int BP, int SP, int *stack, int *RF)
{
	int i;
	// print out instruction and registers
	printf("%2d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t\t", line, opname, IR.r, IR.l, IR.m, PC, SP, BP);
	
	// print register file
	for (i = 0; i < REG_FILE_SIZE; i++)
		printf("%d ", RF[i]);
	printf("\n");
	
	// print stack
	printf("stack:\t");
	for (i = MAX_STACK_LENGTH - 1; i >= SP; i--)
		printf("%d ", stack[i]);
	printf("\n");
}

int base(int L, int BP, int *stack)
{
	int ctr = L;
	int rtn = BP;
	while (ctr > 0)
	{
		rtn = stack[rtn];
		ctr--;
	}
	return rtn;
}

void execute_program(instruction *code, int printFlag)
{
	/// Iniitial values
	int BP = MAX_STACK_LENGTH - 1;
	int SP = BP + 1;
	int PC = 0;
	instruction IR;
	int * stack = calloc(0, sizeof(int));
	int * RF = calloc(REG_FILE_SIZE, sizeof(int));
	int halt = 0;
	
	// keep this
	if (printFlag)
	{
		printf("\t\t\t\t\tPC\tSP\tBP\n");
		printf("Initial values:\t\t\t\t%d\t%d\t%d\n", PC, SP, BP);
	}
	
	/// P-machine instruction cycle
	while (!halt)
	{
		/// Fetch Cycle
		IR = code[PC++];
		
		/// Execute Cycle
		/// Appendix A of hw instructions indicates 23 different operations
		switch (IR.opcode) 
		{
			/// LIT
			case 1: 
				RF[IR.r] = IR.m;
				
			/// RET
			case 2:
				
			/// LOD
			case 3:
				
			/// STO
			case 4:
				
			/// CAL
			case 5: 
				
			/// INC
			case 6:
				
			/// JMP
			case 7:
				PC = IR.m;
				
			/// JPC
			case 8:
				
			/// WRT
			case 9: 
				
			/// RED
			case 10:
				
			/// HAL
			case 11:
				halt = 1;
				
			/// NEG
			case 12:
				
			/// ADD
			case 13:
				
			/// SUB
			case 14:
				
			/// MUL
			case 15:
				
			/// DIV
			case 16:
				
			/// MOD
			case 17:
				
			/// EQL
			case 18:
				
			/// NEQ
			case 19: 
				
			/// LSS
			case 20:
				
			/// LEQ
			case 21:
				
			/// GTR
			case 22:
				
			/// GEQ
			case 23: 
				
		}
	}
}
