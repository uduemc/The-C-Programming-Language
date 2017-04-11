#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

void showTop(void);
void duplicate(void);
void swapItems(void);
void clearStack(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	
	while( (type = getop(s)) != EOF ){
		switch(type){
			case NUMBER:
				push(atof(s));
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
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if(op2 != 0.0){
					push((int)pop()%(int)op2);
				}else
					printf("error: zero divisor\n");
				break;
			case '?':
				showTop();
				break;
			case '#':
				duplicate();
			case '~':
				swapItems();
				break;
			case '!':
				clearStack();
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'c':
				push(cos(pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case 'p':
				op2 = pop();
				push(pow(pop(),op2));
				break;
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

void clearStack(void)
{
	sp = 0;
}

void swapItems(void)
{
	double tmp1 = pop();
	double tmp2 = pop();
	push(tmp1);
	push(tmp2);
}

void duplicate(void)
{
	double tmp = pop();
	push(tmp);
	push(tmp);
}

void showTop(void)
{
	if(sp > 0)
		printf("Top of stack contains: %8g\n",val[sp-1]);
	else
		printf("The stack is empty!\n");
}

int getop(char s[])
{
	int i, c;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;
	i=0;
	if(isdigit(c))
		while(isdigit(s[++i]) == (c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i]) == (c = getch()))
			;
	s[i] = '\0';
	if( c!=EOF )
		ungetch(c);
	return NUMBER;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g \n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

