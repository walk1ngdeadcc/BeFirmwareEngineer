#include <stdio.h>
#include <string.h>
int main() {
    setbuf(stdout, NULL);
    char str1[]="HelloWorld";
    char str2[20]="cc";
    size_t len=strlen(str1);
    printf("%llu\n",len);
    printf("%s\n",str2);

    strcat(str2,str1);
    printf("%s\n",str2);

    strcpy(str2,str1);
    printf("%s",str2);
    return 0;
}