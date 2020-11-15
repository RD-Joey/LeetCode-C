#include<stdio.h>
#include<stdlib.h>
double myPow(double x, int n);
void rotate(int* nums, int numsSize, int k);
int* sortArray(int* nums, int numsSize, int* returnSize);

int main(void)
{
	/*int nums[] = { -1,-100,3,99 };

	rotate(nums, sizeof(nums) / sizeof(int), 2);

	for (int i = 0, n = sizeof(nums) / sizeof(int); i < n; i++)
	{
		printf("%d ", nums[i]);
	}*/

	int nums[] = { 5,2,3,10 };

	int* res = sortArray(nums, sizeof(nums) / sizeof(int), 0);
	for (int i = 0, n = sizeof(nums) / sizeof(int); i < n; i++)
	{
		printf("%d ", res[i]);
	}
	free(res);

	return 0;
}