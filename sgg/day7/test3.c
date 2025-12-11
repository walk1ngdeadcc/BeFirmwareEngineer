#include <stdio.h>
int n = 100;
void func()
{
    n += 10;
    printf("%d", n);
}
int main() {
    setbuf(stdout, NULL);

        func();
        printf("%d", n);
        return 0;
}