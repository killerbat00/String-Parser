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

int main() 
{
	// declarations
	unsigned int len_max = 128;
	unsigned int finalstring_len_max = 81;
	unsigned int current_size = len_max;
	unsigned int i = 0;
	int c;
	
	char *input = malloc(len_max);
	char *finalstring = malloc(finalstring_len_max);	

	//read input, resizing as necessary
	while ((c = getchar()) && c != EOF) {
		input[i++]=(char)c;
		if(i == current_size) {
			current_size = i+len_max;
			input = realloc(input, current_size);
		}
	}
	input[i] = '\0';
	
	//make necessary changes to the input
	i = 0;
	for(c = 0; c < strlen(input) && i < finalstring_len_max-1; c++) {
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
	if(strlen(finalstring) < finalstring_len_max-1 || strlen(input) < finalstring_len_max-1) {
		return 0;
	}

	printf("%s\n", finalstring);
	input = NULL;
	return 0;
}
