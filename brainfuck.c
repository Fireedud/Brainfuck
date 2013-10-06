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
	int lastleft = -1; //This will break any code that has an initial ] w/o a [
	for(i=0; i<s; i++){
		printf("%d %c %d %c\n",  i, line[i], ptr, *ptr);
		switch(line[i]){
			case '>':
				ptr++;
				break;
			case '<':
				ptr--;
				break;
			case '+':
				(*ptr)++;
				break;
			case '-':
				(*ptr)--;
				break;
			case '.':
				putchar(*ptr);
				break;
			case ',':
				*ptr = getchar();
				break;
			case '[':
				lastleft = i;
				if(*ptr == '\0'){
					int j = i;
					while(line[j] != ']'){
						j++;
					}
					i = j;
				}
				break;
			case ']':
				if(*ptr != '\0'){
					i = lastleft;
				}
				break;
			default:
				//do nothing
				break;
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc>0){
		eval(argv[1], setup(SIZE));
	}
	
	return 0;
}
