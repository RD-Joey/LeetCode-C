#include<stdio.h>
#include<stdlib.h>
double myPow(double x, int n);
int* sortArray(int* nums, int numsSize, int* returnSize);
int majorityElement(int* nums, int numsSize);

int main(void)
{
	/*int nums[] = { -1,-100,3,99 };

	rotate(nums, sizeof(nums) / sizeof(int), 2);

	for (int i = 0, n = sizeof(nums) / sizeof(int); i < n; i++)
	{
		printf("%d ", nums[i]);
	}*/

	int nums[] = { 3,2,3 }, returnSize;

	/*int* res = sortArray(nums, sizeof(nums) / sizeof(int), &returnSize);
	for (int i = 0, n = sizeof(nums) / sizeof(int); i < n; i++)
	{
		printf("%d ", res[i]);
	}
	free(res);*/

	//for (int i = 0; i < 3; i++) nums[i]++;
	//for (int i = 0; i < 3; i++) printf("%d ", ++nums[i]);
	printf("%d\n", majorityElement(nums, 3));

	return 0;
}