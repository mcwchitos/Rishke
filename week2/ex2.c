#include <stdio.h>
#include <string.h>

int main(){
    char string[256];
    scanf( "%s" , string );
    //printf(string);
    int i = 0;
    int len = strlen(string);
    for(i = len - 1; i >= 0; i--){
        printf("%c", string[i]);
    }
    return 0;
}
