/****************************************************************************
* Eyal Levi ID.203249073
* Assignment number 3
* Name of project
****************************************************************************/
#include <stdio.h>
#define ARRAY_SIZE 50

void shift_element(int *arr, int i){
    int t = *(arr+i);
    for(int *j=arr+i; j>arr; j--){
        *j = *(j-1);
    }
    *arr = t;
}

void insertion_sort(int *arr, int len){
    for(int i=1; i<len; i++){
        int corr = *(arr+i);
        if(*arr >= corr){
            shift_element(arr, i);
        }
        else{
            for(int j=i; j>=0; j--){
                if(*(arr+j) < corr){
                    shift_element((arr+j+1), (i-j-1));
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
    printArray(nums);
    insertion_sort(nums, ARRAY_SIZE);
    // shift_element(nums+46, 3);
    printf("\n\n");
    printArray(nums);
    return 0;
}