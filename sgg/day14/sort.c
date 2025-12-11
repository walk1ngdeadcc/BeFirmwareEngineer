#include <stdio.h>
void bubbleSort(int arr[],int length) {
    for (int j=0;j<length-1;j++) {
        for (int i = 0; i < length-j-1; ++i) {
            if (arr[i]>arr[i+1]) {
                arr[i]=arr[i]+arr[i+1];
                arr[i+1]=arr[i]-arr[i+1];
                arr[i]=arr[i]-arr[i+1];
            }
        }
    }
}
int main() {
    int arr[] = {3, 1, 5, 4, 2};
    bubbleSort(arr,5);
    for (int i = 0; i < 5; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}