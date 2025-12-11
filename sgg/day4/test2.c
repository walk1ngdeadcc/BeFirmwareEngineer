//
// Created by 14574 on 2025/11/25.
//
#include <stdio.h>
int main() {
    int nums[] = {10, 20, 30, 40, 50, 60, 70};
    int len =sizeof nums/sizeof nums[0];
    printf("元素个数%d\n",len);

    for (int i=0;i<len;i++) {
        printf("%d-%d\n",i,nums[i]);
    }

    return 0;
}