#include <stdio.h>
#include <string.h>

#define SIZE 30000

char *setup(int size)
{
	char tape[size];
	char *ptr = tape;
	return ptr;
}

void eval(char line[], char *ptr)
{
	int s = strlen(line);
	int i = 0;
	for(i=0; i<s; i++){
		switch(line[i]){
			case '>':
				ptr++;
				break;
			case '<':
				ptr--;
				break;
			case '+':
				*ptr++;
				break;
			case '-':
				*ptr--;
				break;
			case '.':
				putchar(*ptr);
				break;
			case ',':
				*ptr = getchar();
				break;
			case '[':
				//to be implemented later
				break;
			case ']':
				//to be implemented later
				break;
			default:
				//do nothing
				break;
		}
