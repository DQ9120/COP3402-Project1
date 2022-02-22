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
	
	/// P-machine instruction cycle
	while (halt == 0)
	{
		/// Fetch Cycle
		IR = code[PC++];
		
		/// Execute Cycle
		/// Appendix A of hw instructions indicate 24 different operations
		switch (IR.opcode) 
		{
			case 0:
			case 1: 
			case 2:
			case 3:
			case 4:
			case 5: 
			case 6:
			case 7:
			case 8:
			case 9: 
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15: 
			case 16:
			case 17:
			case 18:
			case 19: 
			case 20:
			case 21:
			case 22:
			case 23: 
		}
	}
	
	// keep this
	if (printFlag)
	{
		printf("\t\t\t\t\tPC\tSP\tBP\n");
		printf("Initial values:\t\t\t\t%d\t%d\t%d\n", PC, SP, BP);
	}
}
