#include <stdio.h>

int main() {
    setbuf(stdout, NULL);
    int arr[10]={6,25,37,44,11,86,3,56,29,10};
    int min=arr[0];
    int index=0;
    for (int i=1;i<10;i++) {
        min=min<arr[i]?min:arr[i];
        index=min<arr[i]?index:i;
    }
    printf("%d\n",min);
    printf("%d",index);
    return 0;
}