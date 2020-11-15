#include<string.h>
#include<stdlib.h>

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int byteSize = numsSize * sizeof(int), * res = malloc(byteSize);
    memcpy(res, nums, byteSize);
    //*returnSize = numsSize;
    for (int i = 1; i < numsSize; i++) {
        int j = i - 1, temp = res[i];
        while (j >= 0 && res[j] > temp)
            res[j + 1] = res[j--];
        res[j + 1] = temp;
    }
    
    return res;
}