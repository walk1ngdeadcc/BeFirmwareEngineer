#include <stdio.h>

int main() {
    setbuf(stdout,NULL);
    int a;
    printf("hello world");
    scanf("%d", &a);
    return 0;
}