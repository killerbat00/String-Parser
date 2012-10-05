/*
*
*	Author: Brian Morrow
*	COMP530 - Homework 1
*	This program reads input from stdin and writes
*	80 character lines to stdout. If the length of input
*	is less than 80, the program terminates. If length
*	is greater than 80, the output is truncated to 80
*	characters. In the returned output, adjacent pairs
*	of asterisks are replaced by '^' and newlines
*	are replaced by spaces.
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_MAX 128
#define FINALSTRING_LEN_MAX 81


int main() 
{
	// declarations
	unsigned int current_size = LEN_MAX;
	unsigned int i = 0;
	int c;
	
	char *input = malloc(LEN_MAX);
	char *finalstring = malloc(FINALSTRING_LEN_MAX);	

	//read input, resizing as necessary
	while ((c = getchar()) && c != EOF) {
		input[i++]=(char)c;
		if(i == current_size) {
			current_size = i+LEN_MAX;
			input = realloc(input, current_size);
		}
	}
	input[i] = '\0';
	
	//make necessary changes to the input
	i = 0;
	for(c = 0; c < strlen(input) && i < FINALSTRING_LEN_MAX-1; c++) {
		if(input[c] == (int) '*' && input[c+1] == (int) '*') {
			finalstring[i] = '^';
			c +=1;
		} else if(input[c] == (int) '\n') {
			finalstring[i] = ' ';
		} else {
			finalstring[i] = input[c];
		}
	i++;
	}
	
	//enforce bounds
	if(strlen(finalstring) < FINALSTRING_LEN_MAX-1 || strlen(input) < FINALSTRING_LEN_MAX-1) {
		return 0;
	}

	printf("%s\n", finalstring);
	free(input);
	return 0;
}
