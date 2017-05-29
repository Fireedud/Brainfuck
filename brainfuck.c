#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 30000

FILE *debug;

char *setup(int size)
{
	char *ptr = calloc(size, sizeof(int));
	return ptr;
}

/*This should probably grow dynamically
  but this is good for now just to get
  nested brackets to work*/
struct LeftBrackets {
	int loc[100]; //the size can be changed later
	int counter;
};

void eval(char line[], char *ptr, struct LeftBrackets *list)
{
	int i = 0;
	for(i=0; line[i] != EOF && line[i] != '\0'; i++) {
		//printf("%d %c %p %c \t %d %d\n",  i, line[i], ptr, *ptr, list->loc[list->counter-1], list->counter); // for debugging
		fprintf(debug, "%d %c %p %c \t %d %d\n",  i, line[i], ptr, *ptr, list->loc[list->counter-1], list->counter); // for debugging
		switch(line[i]) {
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
				//This leaves the first item in the array blank,
				//but should simplify things.
				if(*ptr == '\0') {
					int j = i;
					while(line[j] != ']'){
						j++;
					}
					i = j;
				} else {
					(list->counter)++;
					if(list->loc[(list->counter)] != i) {
						list->loc[list->counter] = i;
					}
				}
				break;
			case ']':
				if(*ptr != '\0') {
					i = list->loc[list->counter];
				} else {
					(list->counter)--;
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
	debug = fopen("debug.log", "w");
	if(argc>1) {
		printf("%s\n", argv[1]);
		if(strcmp(argv[1], "f") == 0) { //handle files here
			/*FILE *fp = fopen(argv[2], "r");
			char *ptr = setup(SIZE);
			int c = '\0';
			char line[300];
		       	int i = 0;	
			//every ] is considered to be the end of a line
			//the size of this array is arbitrary for now
			while((c = fgetc(fp)) != EOF){
				line[i++] = c;
				if(c == ']'){
					line[i] = '\0';
					eval(line, ptr);
					i = 0;
				}
			}*/
			printf("Sorry, we do not handle files right now.\n");
		} else {
			struct LeftBrackets list;
			list.counter = 0; //initializing it
			eval(argv[1], setup(SIZE), &list);
		}
	} else {
		printf("Need either one or two arguments\n");
	}
	
	return 0;
}
