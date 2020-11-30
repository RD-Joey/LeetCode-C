#include<stdlib.h>
void quickSort(int* nums, int left, int right);

typedef struct {
    int cntl;
    int cntr;
} counter;

counter count(int* nums, int numsSize, int left, int right) {
    counter ret = { 0, 0 };
    while (--numsSize >= 0)
        if (nums[numsSize] == left) ret.cntl++;
        else if (nums[numsSize] == right) ret.cntr++;
    return ret;
}

int cmp(int* ptr1, int* ptr2) { return *ptr1 - *ptr2; }

int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize >> 1];

    /*if (numsSize == 1) return *nums;
    int mid = numsSize >> 1;
    int left = majorityElement(nums, mid);
    int right = majorityElement(nums + mid, numsSize - mid);
    if (left == right) return left;
    else {
        counter c = count(nums, numsSize, left, right);
        return c.cntl > c.cntr ? left : right;
    }*/
}