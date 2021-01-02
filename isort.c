
/****************************************************************************
* Eyal Levi ID.203249073
* Assignment number 3
* https://github.com/LeviEyal
****************************************************************************/
#include <stdio.h>
#define ARRAY_SIZE 50

void shift_element(int *arr, int i){
    for(int *j=arr+i; j>arr; j--){
        *j = *(j-1);
    }
}

void insertion_sort(int *arr, int len){
    for(int i=1; i<len; i++){
        int corr = *(arr+i);
        if(*arr >= corr){
            int t = *(arr+i);
            shift_element(arr, i);
            *arr = t;
        }
        else{
            for(int j=i; j>=0; j--){
                if(*(arr+j) < corr){
                    int t = *(arr+i);
                    shift_element((arr+j+1), (i-j-1));
                    *(arr+j+1) = t;
                    break;
                }
            }
        }
    }
}

void printArray(int *a){
    int i=0;
    for(i=0; i<ARRAY_SIZE-1; i++){
        printf("%d,", *(a+i));
    }
    printf("%d\n", *(a+i));
}

int main() {
    printf("Enter 50 integers:\n");
    int nums[ARRAY_SIZE];
    int i=0;
    while(i<ARRAY_SIZE){
        if(scanf("%d", (nums+i)) == 1)
            i++;
    }
    printf("\nBefore sorting:\n");
    printArray(nums);
    insertion_sort(nums, ARRAY_SIZE);
    printf("\nAfter sorting:\n");
    printArray(nums);
    printf("\n");
    return 0;
}