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
	int BP = MAX_STACK_LENGTH - 1;
	int SP = BP + 1;
	int PC = 0;
	instruction * IR;
	int * stack = calloc(0, sizeof(int));
	int * RF = calloc(REG_FILE_SIZE, sizeof(int));
	// keep this
	if (printFlag)
	{
		printf("\t\t\t\t\tPC\tSP\tBP\n");
		printf("Initial values:\t\t\t\t%d\t%d\t%d\n", PC, SP, BP);
	}
}
