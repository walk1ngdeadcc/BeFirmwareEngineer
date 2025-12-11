#include <stdio.h>

int main() {
    setbuf(stdout, NULL);
    int arr[]={1,2,3,4,5};
    printf("%p\n",arr);
    printf("%p\n",&arr);
    return 0;
}