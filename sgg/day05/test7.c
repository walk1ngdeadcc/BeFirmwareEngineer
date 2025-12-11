#include <stdio.h>
#include <string.h>
int main() {
    setbuf(stdout, NULL);
    char str1[]="xiaoma";
    char str2[]={"xiaolu"};
    char str3[]={'x','i','a','o','q','i','\0'};
    size_t size = strlen(str1);
    for (int i=0;i<size;i++) {
        printf("%c",str1[i]);
    }
    for (int i=0;i<size;i++) {
        printf("%c",str2[i]);
    }
    for (int i=0;i<size;i++) {
        printf("%c",str3[i]);
    }

    return 0;
}