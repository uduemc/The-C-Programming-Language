#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
#define A 1
#define B 2
#define C 3
#define D 4
*/

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE    101
#define MAXLEN      1024
static struct nlist *hashtab[HASHSIZE];
char buffer[MAXLEN];


struct nlist * lookup(char *);
struct nlist * install(char *name, char *defn);
char *strdups(char *);
unsigned hash(char *);
void hashPrintf();
void listPrintf(struct nlist *);

int isDefineLine(char *, int len);
void getNameAndDefn(char *, char *, char *);

// work
void undef(char *);

int main(int argv, char *argc[])
{
	int len;
	char name[MAXLEN];
	char defn[MAXLEN];
	struct nlist *hash;

    // 获取 name defn
    while((len=isDefineLine(buffer, MAXLEN))!=EOF){
		if(len > 0){
            getNameAndDefn(name, defn, buffer);
            if(strlen(name) < 1 || strlen(defn) < 1)
                continue;
            hash = install(name, defn);
            if(hash == NULL){
                printf("error: some error for install()!");
                break;
            }
        }
    }

    // 打印hash表
    hashPrintf();

    undef("A");

    // 打印hash表
    hashPrintf();

    return 0;
}

void undef(char *s)
{
    struct nlist *tmp,*ltmp;
    int i;
    for(i=0; i< HASHSIZE-1;i++){
        if(hashtab[i] == NULL)
            continue;
        tmp = hashtab[i];
        if(strcmp(tmp->name, s) == 0){
            if(tmp->next == NULL){
                free(tmp);
            }else{
                tmp = tmp->next;
                free(hashtab[i]);
                hashtab[i] = tmp;
            }
        }else{
            while(tmp->next != NULL){
                ltmp = tmp;
                tmp = tmp->next;
                if(strcmp(tmp->name, s) == 0){
                    ltmp->next = tmp->next;
                    free(tmp);
                    break;
                }
            }
        }
    }
}

void hashPrintf()
{
    printf("printf: static struct nlist *hashtab[]\n");
    int i;
    for(i=0; i< HASHSIZE-1;i++){
        if(hashtab[i] == NULL)
            continue;
        printf("name: %-12sdefn: %s\n",hashtab[i]->name, hashtab[i]->defn);
        listPrintf(hashtab[i]->next);
    }
}

void listPrintf(struct nlist *tab)
{
    if(tab != NULL){
        printf("name: %-12sdefn: %s\n",tab->name, tab->defn);
        listPrintf(tab->next);
    }
}

void getNameAndDefn(char *name, char *defn, char *buffer)
{
    int i, n;
    i = 8;
    n = 0;
    name[n] = '\0';
    while(buffer[i] != '\0'){
        if(isalnum(buffer[i])){
            name[n++] = buffer[i++];
        }else{
            if(n > 0)
                break;
            i++;
        }
    }
    name[n] = '\0';
    n = 0;
    defn[n] = '\0';
    while(buffer[i] != '\0'){
        if(isalnum(buffer[i])){
            defn[n++] = buffer[i++];
        }else{
            if(n > 0)
                break;
            i++;
        }
    }
    defn[n] = '\0';
}

int isDefineLine(char s[], int len)
{
    char c;
    int n=0;

    while(1){
        if(n>len-1){
            s[n] = '\0';
            break;
        }
        if((c=getchar())==EOF)
            return EOF;
        if(c == '\n'){
            s[n++] = c;
            s[n] = '\0';
            break;
        }else{
            s[n] = c;
        }
        n++;
    }
    if(strlen(s) > 9){
        if(s[0]=='#'&&(s[1]=='d'||s[1]=='D')&&(s[2]=='e'||s[2]=='E')&&(s[3]=='f'||s[3]=='F')&&(s[4]=='i'||s[4]=='I')&&(s[5]=='n'||s[5]=='N')&&(s[6]=='e'||s[6]=='E'))
            return n;
    }
    return 0;
}

struct nlist * install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if( (np = lookup(name)) == NULL ){
        np = (struct nlist *) malloc(sizeof(struct nlist));
        if(np == NULL || (np->name=strdups(name)) == NULL )
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }else
        free(np->defn);
    if((np->defn = strdups(defn)) == NULL)
        return NULL;
    return np;
};
char *strdups(char *s)
{
    char *p;
    p = (char *) malloc(sizeof(char) * strlen(s) + 1);
    if (p == NULL)
        return NULL;
    strcpy(p, s);
    return p;
}

struct nlist * lookup(char *s)
{
    struct nlist *np;
    for(np=hashtab[hash(s)]; np != NULL; np=np->next)
        if(strcmp(s, np->name) == 0)
            return np;
    return NULL;
};

unsigned hash(char *s)
{
    unsigned hashval;
    for(hashval=0; *s!='\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

