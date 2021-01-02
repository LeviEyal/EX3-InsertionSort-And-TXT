
/****************************************************************************
* Eyal Levi ID.203249073
* Assignment number 3
* https://github.com/LeviEyal
****************************************************************************/

#include <stdio.h>
#include <ctype.h>

#define LINE 256
#define WORD 30
int getLine(char s[]);
int getword(char s[]);
int substring(char *s1, char *s2);
int similar(char *s, char *t, int n);
void printLines(char *s);
void printSimilarWords(char *s);
void testSimilar();
int strLen(char* s);
void testStrLen();
void testPrintSimilarWords();
void testPrintLines();
void testGetWord();

int main() {

    // testGetLine();
    // testGetWord();
    // testSubstring();
    // testSimilar();
    // testStrLen();
    // testPrintSimilarWords();
    // testPrintLines();
    
    char word[WORD];
    scanf(" %s", word);
    char ch;
    scanf(" %c", &ch);

    if(ch == 'a'){
        printLines(word);
    }
    if(ch == 'b'){
        printSimilarWords(word);
    }
}

int getLine(char s[]){
    int i=0;
    char c;
    while((c=getchar())!='\n' && c!=EOF){
        s[i] = c;
        i++;
    }
    s[i] = 0;
    // return scanf("%[^\n]%c", s);
    if(c!=EOF)
        return i+1;
    return i;
}

int getword(char s[]){
    int i=0;
    char c;
    while(!isspace(c=getchar()) && c!=EOF){
        s[i] = c;
        i++;
    }
    s[i] = 0;
    if(c!=EOF)
        return i+1;
    return i;
}

int substring(char *s1, char *s2){
    char *t = s2;
    while(*s1){
        s2 = t;
        while(*s1 == *s2){
            s1++;
            s2++;
            if(*s2 == 0) return 1;
        }
        s1++;
    }
    return 0;
}

int similar(char *s, char *t, int n){
    if(strLen(s) < strLen(t)) return 0;
    while(*s){
        if(*t){
            if(*s != *t) n--;
            else t++;
        }
        else{
            n--;
        }
        s++;
    }
    return n==0;
}

void printLines(char *s){
    char t[LINE];
    while(getLine(t)){
        if(substring(t, s))
            printf("%s\n",t);
    }
}

void printSimilarWords(char *s){
    char t[WORD];
    while(getword(t)){
        if(similar(t, s, 1) || similar(t, s, 0))
            printf("%s\n", t);
    }
}

int strLen(char* s){
    int len = 0;
    while(*s){
        len++;
        s++;
    }
    return len;
}
//=========================== TESTS ================================
void testGetLine(){
    char s[LINE];
    while(getLine(s)){
        printf("%s\n",s);
    }
}

void testGetWord(){
    char s[WORD];
    while(getword(s)){
        printf("%s\n",s);
    }
}

void testSubstring(){
    char* s = "eyal";
    printf("eyal %d\n", substring(s, "eyal"));
    printf("e %d\n", substring(s, "e"));
    printf("y %d\n", substring(s, "y"));
    printf("a %d\n", substring(s, "a"));
    printf("l %d\n", substring(s, "l"));
    printf("yal %d\n", substring(s, "yal"));
    printf("eyl %d\n", substring(s, "eyl"));
    printf("eya %d\n", substring(s, "eya"));
    printf("ey %d\n", substring(s, "ey"));
    printf("al %d\n", substring(s, "al"));
    printf("yl %d\n", substring(s, "yl"));
    printf("ea %d\n", substring(s, "ea"));
    printf("ea %d\n", substring(s, " "));
    printf("ea %d\n", substring(s, ""));
}

void testSimilar(){
    char* s = "swsystems";
    char* t = "ssysems";
    printf("%d shoud be 1\n", similar(s, t, 2));
    printf("%d shoud be 0\n", similar(s, t, 0));
    printf("%d shoud be 1\n", similar("eya", "y", 2));
    printf("%d shoud be 0\n", similar("ey", "eya", 0));
    printf("%d shoud be 0\n", similar("eyal", "yal", 0));
    printf("%d shoud be 1\n", similar("eyal", "eyal", 0));
    printf("%d shoud be 1\n", similar("eyal", "yal", 1));
    printf("%d shoud be 0\n", similar("eyal", "yal", 2));
    printf("%d shoud be 1\n", similar("eyal", "e", 3));
    printf("%d shoud be 1\n", similar("eyal", "y", 3));
    printf("%d shoud be 1\n", similar("eyal", "a", 3));
    printf("%d shoud be 1\n", similar("eyal", "l", 3));
    printf("%d shoud be 1\n", similar("eyal", "el", 2));
    printf("%d shoud be 1\n", similar("eyal", "al", 2));
    printf("%d shoud be 1\n", similar("eyal", "ea", 2));
    printf("%d shoud be 1\n", similar("eyal", "ya", 2));
    printf("%d shoud be 1\n", similar("eyal", "ey", 2));
    printf("%d shoud be 0\n", similar("eyal", "eyal", 1));
    printf("%d shoud be 0\n", similar("eyal", "eyal", 2));
    printf("%d shoud be 0\n", similar("eyal", "eyal", 3));
}

void testStrLen(){
    printf("%d\n", strLen("e"));
    printf("%d\n", strLen("ey"));
    printf("%d\n", strLen("eya"));
    printf("%d\n", strLen("eyal"));
    printf("%d\n", strLen("eyalu"));
    printf("%d\n", strLen("eyalus"));
    printf("%d\n", strLen("eyalush"));
}

void testPrintSimilarWords(){
    printSimilarWords("cat");
}

void testPrintLines(){
    printLines("cat");
}