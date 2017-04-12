#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 			100
#define NUMBER 			0
#define IDENTIFIER 		1
#define ENDSTRING 		2
#define TRUE 			1
#define FALSE 			0
#define MAX_ID_LEN		32
#define MAXVARS			30
#define BUFSIZE 		100
#define MAXVAL 			100


struct varType{
	char name[MAX_ID_LEN];
	double val;
};

int Getop(char s[]);
void push(double val);
double pop(void);
void showTop(void);
void duplicate(void);
void swapItems(void);
int getch(void);
void unGetch(int);

void clearStacks(struct varType var[]);
void dealWithName(char s[], struct varType var[]);
void dealWithVar(char s[], struct varType var[]);

int pos = 0;
struct varType last;
int buf[BUFSIZE];
int bufp = 0;
int sp = 0;
double val[MAXVAL];

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	struct varType var[MAXVARS];
	
	clearStacks(var);
	
	while((type = Getop(s)) != EOF){
		switch(type){
			case NUMBER:
				push(atof(s));
				break;
			case IDENTIFIER:
				dealWithName(s, var);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2)
					push(pop()/op2);
				else
					printf("\nError: division by zero!");
				break;
			case '%':
				op2 = pop();
				if(op2)
					push(fmod(pop(), op2));
				else
					printf("\nError: division by zero!");
				break;
			case '?':
				showTop();
				break;
			case '#':
				duplicate();
				break;
			case '~':
				swapItems();
				break;
			case '!':
				clearStacks(var);
				break;
			case '\n':
				printf("\n\t%.8g\n",pop());
				break;
			case ENDSTRING:
				break;
			case '=':
				pop();
				var[pos].val = pop();
				last.val = var[pos].val;
				push(last.val);
				break;
			case '<':
				printf("The last variable used was: %s (value == %g)\n",last.name, last.val);
				break;
			default:
				printf("\nError: unknow command \"$s\".\n", s);
				break;
		}
	}
	return EXIT_SUCCESS;
}

void push(double f)
{
	if(sp > MAXVAL)
		val[sp++] = f;
	else
		printf("\nError: stack full can't push %g\n",f);
}

double pop(void)
{
	if( sp > 0){
		return val[--sp];
	}else{
		printf("\nError: stack empty\n");
		return 0.0;
	}
}

void showTop(void)
{
	if(sp > 0)
		printf("Top of stack contains: %8g\n",val[sp-1]);
	else
		printf("The stack is empty\n");
}

void duplicate(void)
{
	double temp = pop();
	push(temp);
	push(temp);
}

void swapItems(void)
{
	double item1 = pop();
	double item2 = pop();
	push(item1);
	push(item2);
}

void clearStacks(struct varType var[])
{
	int i;
	sp = 0;
	for(i = 0; i< MAXVARS; i++)
	{
		var[i].name[0] = '\0';
		var[i].val = 0.0;
	}
}

void dealWithName(char s[], struct varType var[])
{
	double op2;
	if(!strcmp(s,"sin"))
		push(sin(pop()));
	else if(!strcmp(s,"cos"))
		push(cos(pop()));
	else if(!strcmp(s,"exp"))
		push(exp(pop()));
	else if(!strcmp(s,"pow")){
		op2 = pop();
		push(pow(pop(), op2));
	}
	else{
		dealWithVar(s, var);
	}
}

void dealWithVar(char s[], struct varType var[])
{
	int i = 0;
	while(var[i].name[0] != '\0' && i < MAXVARS -1)
	{
		if(!strcmp(s, var[i].name)){
			strcpy(last.name, s);
			last.val = var[i].val;
			push(var[i].val);
			pos = i;
			return ;
		}
		i++;
	}
	
	strcpy(var[i].name, s);
	strcpy(last.name, s);
	push(var[i].val);
	pos = i;
}

int Getop(char s[])
{
	int i = 0;
	int c;
	int next;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(isalpha(c)){
		i = 0;
		while(isalpha(s[i++]  = c)){
			c = getch();
		}
		s[i - 1] = '\0';
		if(c != EOF)
			unGetch(c);
		return IDENTIFIER;
	}
	
	if(!isdigit(c) && c!= '.' && c!='-'){
		if('=' == c && '\n' == (next=getch())){
			unGetch('\0');
			return c;
		}
		if('\0' == c)
			return ENDSTRING;
		return c;
	}
	
	if(c == '-'){
		next = getch();
		if(!isdigit(next) && next != '.'){
			return c;
		}
		c = next;
	}else{
		c = getch();
	}
	
	while(isdigit(s[++i] = c)){
		c = getch();
	}
	if(c == '.'){
		while(isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';
	if( c != EOF )
		unGetch(c);
	return NUMBER;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp]: getchar();
}

void unGetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("\nUnGetch: too many characters\n");
	else
		buf[bufp++] = c;
}