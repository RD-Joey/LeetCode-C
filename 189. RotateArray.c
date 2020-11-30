static _Bool left = 0;
void swapGroups(int* nums, int size, int k);
int GCD(int n, int m);

void rotate(int* nums, int numsSize, int k) {
    //k %= numsSize;
    //reverse(nums, 0, numsSize - k - 1);
    //reverse(nums, numsSize - k, numsSize - 1);
    //reverse(nums, 0, numsSize - 1);

    //k %= numsSize;
    //if (k) {
    //    left = 0;
    //    swap(nums, numsSize, k);
    //}

    k %= numsSize;
    if (!k) return;
    k = numsSize - k;
    for (int i = 0, n = GCD(numsSize, k); i < n; i++)
    {
        int j = i, temp = nums[i];
        for (int step = (j + k) % numsSize; step != i; j = step, step = (step + k) % numsSize)
            nums[j] = nums[step];
        nums[j] = temp;
    }
}

void swapGroups(int* nums, int size, int k) {
    if (k > size >> 1) {
        k = size - k;
        left = !left;
    }
    for (int i = 0, j = size - k; i < k; i++)
    {
        nums[i] ^= nums[j + i];
        nums[j + i] ^= nums[+ i];
        nums[i] ^= nums[j + i];
    }

    if (k << 1 != size) {
        if (left) swapGroups(nums, size - k, k);
        else swapGroups(nums + k, size - k, k);
    }
}

void reverse(int* nums, int l, int r) {
    for (int i = 0, n = r - l + 1 >> 1; i < n; i++)
    {
        nums[l + i] ^= nums[r - i];
        nums[r - i] ^= nums[l + i];
        nums[l + i] ^= nums[r - i];
    }
 }

int GCD(int n, int m)
{
    for (int b = 1; b; b = n % m, n = m, m = b);
    return n;
}