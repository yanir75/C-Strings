#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TXT 1024
#define WORD 30
char * getWord(){
    char * w = (char *)malloc(sizeof(char)*WORD);
    if(w==NULL){
        exit(1);
    }
    char ch;
    scanf("%c",&ch);
    int ind=0;
    while(ch!=' ' && ch!='\n' && ch!='\t'){
        w[ind]=ch;
        ind++;
        scanf("%c",&ch);
    }
    return w;
}
char * getText(){
    char * w = (char *)malloc(sizeof(char)*TXT);
    if(w==NULL){
        exit(3);
    }
    char ch;
    scanf("%c",&ch);
    int ind=0;
    while(ch!='~'){
        w[ind]=ch;
        ind++;
        scanf("%c",&ch);
    }
    return w;
}
int check(char ch){
    if(ch<123 && ch >96)
    return ch-96;
    if(ch<91 && ch >64)
    return ch-64;
    return 0;
}
int check_sum(char * w,int ind){
    int sum=0;
    for(int i=0;i<ind;i++){
        sum = sum+check(w[i]);
    }
    return sum;
}
int check_gem(char * txt, int sum){
    printf("Gematria Sequences: ");
    int ind;
    int first =0;
    for(int i=0;i<strlen(txt);i++){
        ind=0;
        while(i<strlen(txt) && (check(txt[i])==0))
        i++;
        char * subW = (char *)malloc(sizeof(txt));
        if(subW==NULL){
            exit(5);
        }
        if(i<strlen(txt)){
        subW[ind]=txt[i];
        ind++;
        }
        while(i+ind<strlen(txt) && check_sum(subW,ind)<sum)
        {
            subW[ind] = txt[i+ind];
            ind++;
        }
        if(first==0)
        {
        if(check_sum(subW,ind)==sum){
            printf("%s",subW);
            first=1;
        }
        }
        else
        {
        if(check_sum(subW,ind)==sum){
            printf("~%s",subW);
        }
        }
        free(subW);
    }
    putchar('\n');
    return 1;
}
char check_ch(char ch){
    if(ch<123 && ch >96){
        return 219-ch;
    }
    if(ch<91 && ch >64){
    return (155-ch);
    }
    return ch;
}
char * atb(char * w){
    char *bW = (char *)malloc(sizeof(w));
    for(int i=0;i<strlen(w);i++){
        bW[i] = check_ch(w[i]);
    }
    return bW;
}
char * atb_b(char * w){
    char *bW = (char *)malloc(sizeof(w));
    int ind =0;
    for(int i=strlen(w)-1;i>-1;i--){
        bW[ind] = check_ch(w[i]);
        ind++;
    }
    return bW;
}
int atbash(char * word, char * txt){
    printf("Atbash Sequences: ");
    int first= 0;
    for(int i=0;i<strlen(txt);i++){
        int ind=0;
        int ind1=0;
        char * w = atb(word);
        char * wc = (char *)malloc(sizeof(txt));
        if(wc==NULL)
        exit(10);
        while(ind<strlen(w)&&i+ind1<strlen(txt)&&w[ind]==txt[i+ind1]){
            wc[ind1] = txt[i+ind1];
            ind++;
            ind1++;
            while(txt[i+ind1]==' '){
                wc[ind1] = txt[i+ind1];
                ind1++;
            }
        }
        if(first==0){
          if(ind==strlen(w)){
            printf("%s",wc);
            first=1;
        }  
        }
        else{
        if(ind==strlen(w)){
            printf("~%s",wc);
        }
        }
        free(wc);
        ind=0;
        ind1=0;
        w = atb_b(word);
        wc = (char *)malloc(sizeof(txt));
        if(wc==NULL)
        exit(10);
        while(ind<strlen(w)&&i+ind1<strlen(txt)&&w[ind]==txt[i+ind1]){
            wc[ind1] = txt[i+ind1];
            ind++;
            ind1++;
            while(txt[i+ind1]==' '){
                wc[ind1] = txt[i+ind1];
                ind1++;
            }
        }
        if(first==0){
          if(ind==strlen(w)){
            printf("%s",wc);
            first=1;
        }  
        }
        else{
        if(ind==strlen(w)){
            printf("~%s",wc);
        }
        }
        free(wc);
    }
    putchar('\n');
    return 1;
}
int check_anagram(char * w, char * w1){
    int wF[256]={0};
    int wS[256]={0};
    for(int i=0;i<strlen(w);i++){
        if(w[i]!=' '){
            wF[w[i]]++;
        }
    }
    for(int i=0;i<strlen(w1);i++){
    if(w1[i]!=' '){
            wS[w1[i]]++;
        }
    }
for (int i=0;i<256;i++)
{
if (wF[i]!= wS[i])
return 0;
}
return 1;
}
int anagram(char * word , char * txt,int sum){
       printf("Anagram Sequences: ");
    int ind;
    int first =0;
    for(int i=0;i<strlen(txt);i++){
        ind=0;
        while(i<strlen(txt) && (check(txt[i])==0))
        i++;
        char * subW = (char *)malloc(sizeof(txt));
        if(subW==NULL){
            exit(5);
        }
        if(i<strlen(txt)){
        subW[ind]=txt[i];
        ind++;
        }
        while(i+ind<strlen(txt) && check_sum(subW,ind)<sum)
        {
            subW[ind] = txt[i+ind];
            ind++;
        }
        if(first==0)
        {
        if(check_anagram(subW,word)==1){
            printf("%s",subW);
            first=1;
        }
        }
        else
        {
        if(check_anagram(subW,word)==1){
            printf("~%s",subW);
        }
        }
        free(subW);
    }
    return 1; 
}
