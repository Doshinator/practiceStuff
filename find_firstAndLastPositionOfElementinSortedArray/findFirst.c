#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);
int binSearch(int *nums, int l, int r, int target); 
int lastBinSearch(int *nums, int l, int r, int target);
int firstBinSearch(int *nums, int l, int r, int target);

int main(){
    int i = 0;
    int numSize = 6;
    int target = 8;
    int *returnSize;
    int *nums = (int*)malloc(sizeof(int) * numSize);
    nums[0] = 5;
    nums[1] = 7;
    nums[2] = 7;
    nums[3] = 8;
    nums[4] = 8;
    nums[5] = 10;

    printf("Input: nums = [");
    for(size_t i = 0 ; i < numSize ; i++){
        printf("%d ", nums[i]);
    }
    printf("] target = %d\n", target);
    returnSize = searchRange(nums, numSize, target, returnSize);
    // returnSize[1] = 5;
    printf("Output : ");
    printf("[%d, %d]\n" , returnSize[0], returnSize[1]);
    free(nums);
    free(returnSize);
    return 0;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int i;
    returnSize = (int*)malloc(sizeof(int) * 2);
    for(size_t i = 0 ; i < 2 ; i++){
        returnSize[i] = -1;
    }
    
    // printf("\n %d" , binSearch(nums, 1, numsSize, target));
    //returnSize[0] = binSearch(nums, 1, numsSize, target);
    returnSize[0] = firstBinSearch(nums, 1, numsSize, target);
    returnSize[1] = lastBinSearch(nums, 1, numsSize, target);
    // returnSize[1] =
    printf("\n");
    return returnSize;
}

int binSearch(int *nums, int l, int r, int target){
    int mid = (l + r - 1) / 2;
    if(nums[mid] == target)
        return mid;
    if(nums[mid] > target){
        return binSearch(nums, l ,mid - 1, target);
    }
    else{
        return binSearch(nums, mid + 1, r, target);
    }
    return -1;
    
}

int lastBinSearch(int *nums, int l, int r, int target){
    if(r >= l){
        int mid = (l + r - 1) / 2;
        if(target < nums[mid + 1] && nums[mid] == target)
            return mid;
        else if(target < nums[mid])
            return lastBinSearch(nums, l, (mid -1), target);
        else
            return lastBinSearch(nums, mid + 1, r, target);
    }
    return -1;
}

int firstBinSearch(int *nums, int l, int r, int target){
    if(r >= l){
        int mid = (l + r - 1) / 2;
        if( ( mid == 0 || target > nums[mid - 1]) && nums[mid] == target) 
            return mid;
        else if(target > nums[mid])
            return firstBinSearch(nums, mid + 1, r, target);
        else
            return firstBinSearch(nums, l, mid - 1, target);
    }
    return -1;
}