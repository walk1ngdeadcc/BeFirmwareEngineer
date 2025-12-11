#include <stdio.h>

int main() {
    setbuf(stdout,NULL);
        int a;
        printf("输入一个数：\n");
        scanf("%d",&a);
        if (a<=1) {
            printf("非法数字\n");
        }else if (a==2) {
            printf("该数是质数\n");
        }else {
            for (int i=2;i<a;i++) {
                if (a%i==0) {
                    printf("该数不是质数\n");
                    break;
                }

            }
        }
    return 0;
}