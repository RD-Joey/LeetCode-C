#include<string.h>
#include<stdlib.h>

void swap(int* arr, int a, int b) {
    if (a == b) return;
    arr[a] ^= arr[b];
    arr[b] ^= arr[a];
    arr[a] ^= arr[b];
}

void insertionSort(int* nums, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int tmp = nums[i], j = i - 1;
        while (j >= left && nums[j] > tmp) nums[j + 1] = nums[j--];
        nums[j + 1] = tmp;
    }
}

void quickSort(int* nums, int left, int right) {
    if (right - left < 15) return insertionSort(nums, left, right);
    swap(nums, left, left + (right - left >> 1));
    int lt = left, i = left + 1, gt = right;
    //  nums(left, lt] < pivot, nums(lt, i) == pivot, nums(gt, r] > pivot
    while (i <= gt) {
        if (nums[i] < nums[left]) swap(nums, ++lt, i++);
        else if (nums[i] > nums[left]) swap(nums, i, gt--);
        else i++;
    }
    swap(nums, left, lt);
    if (left < lt - 1) quickSort(nums, left, lt - 1);
    if (gt + 1 < right) quickSort(nums, gt + 1, right);
}

void mergeSort(int* src, int* dest, int left, int right) {
    if (right - left < 1) return;
    int mid = left + ((right - left) >> 1);
    mergeSort(dest, src, left, mid);
    mergeSort(dest, src, mid + 1, right);
    if (src[mid] <= src[mid + 1]) {
        memcpy(dest + left, src + left, sizeof(int) * (right - left + 1));
        return;
    }
    int k = left, i = k, j = mid + 1;
    while (i <= mid && j <= right) {
        if (src[i] <= src[j]) dest[k++] = src[i++];
        else dest[k++] = src[j++];
    }
    if (i > mid)
        while (j <= right) dest[k++] = src[j++];
    else while (i <= mid) dest[k++] = src[i++];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int* dest = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    memcpy(dest, nums, sizeof(int) * numsSize);
    if (numsSize > 1)
        quickSort(dest, 0, numsSize - 1);
    return dest;

    /** BucketSort
    int count[100001] = { 0 };
    int* dest = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
        count[50000 + nums[i]]++;
    for (int i = 0, j = 0; j < numsSize && i < 100001; i++)
        while (count[i]--) dest[j++] = i - 50000;
    return dest;*/
}
