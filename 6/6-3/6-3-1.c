#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct variable{
    char *word;
    char *lins;
    int count;
    struct variable *left;
    struct variable *right;
};

int getword(char *, int);
struct variable *addVariable(struct variable *, char *);
void treePrint(struct variable *);
struct variable *talloc(void);
char *strsetup(char *);
char *strappend(char *, char *);
int lineNo = 1;

int main(int argv, char *argc[])
{
    char word[MAXWORD];
    struct variable *root;
    while(getword(word, MAXWORD) != EOF){
		if(strlen(word) > 1)
			root = addVariable(root, word);
	}
    treePrint(root);
    return 0;
}



struct variable *addVariable(struct variable *p, char *s)
{
    int cond;
    char str[25];

    if (p == NULL){
        p = talloc();
        p->word = strsetup(s);
        p->count = 1;
        p->left = NULL;
        p->right = NULL;
		sprintf(str, "%d", lineNo);
        p->lins = strsetup(str);

    }else{
        cond = strcmp(p->word, s);
        if(cond == 0){
			sprintf(str, "%d", lineNo);
			p->lins = strappend(p->lins,str);
            p->count++;
		}else if(cond < 0)
            p->left = addVariable(p->left, s);
        else if(cond > 0)
            p->right = addVariable(p->right, s);
    }

    return p;
};

struct variable *talloc(void)
{
    return (struct variable *)malloc(sizeof(struct variable));
};

char *strappend(char *s, char *t)
{
    char *p;
    int sl;
    sl = strlen(s) * sizeof(char) + strlen(t) * sizeof(char) + 2;
    p = (char *)malloc(sl);
    if(p != NULL){
        strcat(p, s);
        strcat(p, ",");
        strcat(p, t);
    }
    return p;
}

char *strsetup(char *s)
{
    char *p;
    p = (char *)malloc(strlen(s) * sizeof(char) + 1);
    if(p != NULL)
        strcpy(p, s);
    return p;
}

void treePrint(struct variable *root)
{
    if( root != NULL){
        treePrint(root->left);
        printf("word: %-12s\tcount: %d\tline: %s\n",root->word, root->count, root->lins);
        treePrint(root->right);
    }
}

int getword(char *s, int len)
{
    int n = 0;
    char c,lc = '\0';
	int isNote = 0,isNotes = 0;

	while(1)
	{
	    c = getchar();
		if(c == EOF)
			return EOF;

        if(c == '\n'){
            lineNo++;
        }

        // 单行注释
        if(c == '/' && lc == '/'){
            isNote = 1;
        }
        if(isNote == 1 && c == '\n'){
            isNote = 0;
            continue;
        }
        if (isNote == 1)
            continue;

        // 多行注释
        if(c == '*' && lc == '/'){
            isNotes = 1;
        }
        if(isNotes == 1 && c == '/' && lc == '*'){
            isNotes = 0;
            continue;
        }
        if (isNotes == 1)
            continue;

        if(!isalpha(c)){
            s[n] = '\0';
            return n;
        }
		if(n == 0){
			if(isspace(c) || c == '\n' || c == '_')
				continue;
			s[n++] = c;
		}else{
			if(isspace(c) || c == '\n' || c == '_'){
				s[n] = '\0';
				return n;
			}
			s[n++] = c;

		}
        lc = c;
	}

    return n;
}