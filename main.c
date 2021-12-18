#include "dec.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char * x = getWord();
    char * y = getText();
    check_gem(y,check_sum(x,strlen(x)));
    atbash(x,y);
    anagram(x,y,check_sum(x,strlen(x)));
    free(x);
    free(y);
    return 0;
}
