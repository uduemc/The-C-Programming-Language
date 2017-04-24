#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key{
    char *word;
    int count;
} keytab[] = {
    {"auto",0},
    {"short",0},
    {"int",0},
    {"long",0},
    {"float",0},
    {"double",0},
    {"char",0},
    {"struct",0},
    {"union",0},
    {"enum",0},
    {"typedef",0},
    {"const",0},
    {"unsigned",0},
    {"signed",0},
    {"extern",0},
    {"register",0},
    {"static",0},
    {"volatile",0},
    {"void",0},
    {"if",0},
    {"else",0},
    {"switch",0},
    {"case",0},
    {"for",0},
    {"do",0},
    {"while",0},
    {"goto",0},
    {"continue",0},
    {"break",0},
    {"default",0},
    {"sizeof",0},
    {"return",0}
};

int getword(char *, int);
int binsearch(char *, struct key *, int);
int main()
{
    int n;
    char word[MAXWORD];
    int nkeys = sizeof(keytab) / sizeof(keytab[0]);

    while (getword(word, MAXWORD) != EOF){
        if(isalpha(word[0]))
            if(( n = binsearch(word, keytab, nkeys)) >=0 )
                keytab[n].count++;
    }

    for(n=0;n<nkeys;n++){
        if(keytab[n].count > 0)
            printf("word: %s\t count:%d\n",keytab[n].word,keytab[n].count);
    }

    return 0;
}

int binsearch(char *s, struct key *keytab, int len)
{
    int n;
    for(n=0; n < len; n++){
        if(strcmp(s,keytab[n].word) == 0)
            return n;
    }
    return -1;
}

int getword(char *s, int len)
{
    int n = 0;
    char c,lc = '\0',llc = '\0';
	int isNote = 0,isNotes = 0;

	while(c = getchar())
	{
		if(c == EOF)
			return EOF;

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
		llc = lc;
        lc = c;
	}

    return n;
}
