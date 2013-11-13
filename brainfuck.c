#include <stdio.h>
#include <string.h>

#define SIZE 30000

char *setup(int size)
{
	char tape[size];
	char *ptr = tape;
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
	for(i=0; line[i] != EOF && line[i] != '\0'; i++){
		printf("%d %c %d %c \t %d %d\n",  i, line[i], ptr, *ptr, list->loc[list->counter-1], list->counter); // for debugging
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
				list->loc[list->counter++] = i;
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
					i = list->loc[list->counter--];
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
		if(strcmp(argv[1], "f") == 0){ //handle files here
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
