/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int i, j, temp;
    for(i = 0; i < numsSize-1; i++) {
        for(j = 0; j < numsSize-i-1; j++) {
            if(nums[j] % 2 != 0 && nums[j+1] % 2 == 0) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    *returnSize = numsSize;
    return nums;
}
