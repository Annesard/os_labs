#include<stdio.h>
#include <string.h>


int main(){
    char str[100], rev[100];
    char c;
    int i = 0, j=0;
    while((c= getchar())!='\n'){
        str[i] = c;
        ++i;
    }
    int size = strlen(str);
   
    
    for( i = size - 1; i >= 0; i--){
        rev[j++] = str[i];
    }
    
    rev[i] = '\0';
    printf("%s", rev);
    return 0;
}
