/*
*	Author: Brian Morrow
*	COMP530 - Homework 1
*	This program reads input from stdin and writes
*	80 character lines to stdout. If the length of input
*	is less than 80, the program terminates. If length
*	is greater than 80, the output is truncated to 80
*	character only lines. Any line that ends up being
*	less than 80 characters is not printed.
*	In the returned output, adjacent pairs of asterisks
*	are replaced by '^' and newlines are replaced by
*	spaces.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN_MAX 128

int main() 
{
	// declarations
	unsigned int current_size = LEN_MAX;
	unsigned int i = 0;
	int c;

	char *input = malloc(LEN_MAX);
	char *middlestring, *finalstring, *output;
	char *lastocc;
	
	//read input, resizing as necessary
	while ((c = getchar()) && c != EOF) {
		input[i++]=(char)c;
		if(i == current_size) {
			current_size = i+LEN_MAX;
			input = realloc(input, current_size);
		}
	}
	//null terminate input
	input[i] = '\0';

	//resize buffers to prevent overflow	
	middlestring = malloc(current_size);
	finalstring = malloc(current_size);
	output = malloc(current_size);

	//make necessary changes to the input
	for(c = 0, i = 0; c < strlen(input) && i < current_size; c++, i++) {
		if(input[c] == (int) '*' && input[c+1] == (int) '*') {
			middlestring[i] = '^';
			c +=1;
		} else if(input[c] == (int) '\n') {
			middlestring[i] = ' ';
		} else {			
			middlestring[i] = input[c];		
		}
	}

	//first size test	
	if (strlen(middlestring) < 80) {
		return 0;
	}

	//New way to check for string line lengths and break into 80 char pieces
	for (c = 0,i = 0;c < strlen(middlestring) && i < strlen(middlestring); c++, i++) {
		if ((c >= 80) && (c % 80 == 0)) {
			finalstring[i] = '\n';
			finalstring[i+1] = middlestring[c];
			i+=1;
		} else {
			finalstring[i] = middlestring[c];
		}
	}	

	//Ensure that there are no dangling lines < 80 chars.
	if (strlen(finalstring) > 81) {
		lastocc = strrchr(finalstring, '\n');			
		if ((strlen(finalstring) - (lastocc-finalstring+1)) < 80) {
			strncpy(output, finalstring, (lastocc-finalstring));
			//null terminate like a good boy
			output[(lastocc-finalstring)+1] = '\0';
		}
	}

	printf("%s\n", output);
	free(input);
	free(middlestring);
	free(finalstring);
	free(output);
	return 0;
}
