#include <stdio.h>

int main() {
    setbuf(stdout, NULL);
    int nums[3][4] = {
        {1, 2, 3, 4},
        {11, 12, 13, 14},
        {21, 22, 23, 24}
    };
    int j=0;
    int a=0;
    for(int i=0;i<12;i++) {
        printf("%d ",nums[j][a]);
        a++;
        if (a%4==0) {
            j++;
            a=0;
            printf("\n");
        }

    }
    return 0;
}