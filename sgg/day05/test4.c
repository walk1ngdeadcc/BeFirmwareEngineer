#include <stdio.h>

int main() {
    setbuf(stdout, NULL);
    char arr[26];
    for (int j=0,i='A';j<26&&i<='Z';j++,i++) {
        arr[j]=i;
    }
    for (int i=0;i<26;i++) {
        printf("%c ",arr[i]);
    }
    return 0;
}