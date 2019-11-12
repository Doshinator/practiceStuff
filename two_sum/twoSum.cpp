#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

/*
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].

*/

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int compliment = 0;
        int i, j = 0;
        std::vector<int> sol (2, 0);
        for(i = 0; i < nums.size(); ++i){
            compliment = target - nums[i];
            for(j = 0; j < nums.size(); ++j){
                if(compliment == nums[j]){
                     sol[0] = j;
                     sol[1] = i;
                }
            }
        }

        return sol;

    }
};

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    returnSize[0] = -1;
    returnSize[1] = -1;
    int compliment = 0;
    int i, j = 0;
    for(i = 0; i < numsSize; ++i){
        compliment = target - nums[i];
        for(j = 0; j < numsSize; ++j){
            if(nums[j] == compliment){
                returnSize[0] = j;
                returnSize[1] = i;
            }
        }
    }
    if(returnSize[0] == returnSize[1]) {
        returnSize[0] = returnSize[1] = -1;
        return returnSize;
    }else {
        return returnSize;
    }
    
}

int main(){
    int *returnSize = (int*)malloc(2 * sizeof(int));
    returnSize[0] = returnSize[1] = 0;

    int *nums = (int*)malloc(4 * sizeof(int));
    nums[0] = 2;
    nums[1] = 7;
    nums[2] = 11;
    nums[3] = 15;

    int numSize = 4;
    int target = 26;

    

    returnSize = twoSum(nums, numSize, target, returnSize);
    printf("[%d, %d]\n", returnSize[0], returnSize[1]);
    free(nums);
    free(returnSize);


    
    EX ---- vector<int> num

    std::vector<int> sol (2, 0);
    std::vector<int> num;
    num.push_back(2);
    num.push_back(7);
    num.push_back(11);
    num.push_back(15);



    Solution s1;
    sol = s1.twoSum(num, target);
    std::cout << "[" << sol.front() << ", ";
    std::cout << sol.front() + 1 << "]" << std::endl;


    /*
    // EX ---- vector<int> *num

        std::vector<int> sol (2, 0);
        std::vector<int> *num = new std::vector<int> ();
        num->push_back(2);
        num->push_back(7);
        num->push_back(11);
        num->push_back(15);



        Solution s1;
        sol = s1.twoSum(num[0], target);
        std::cout << "[" << sol.front() << ", ";
        std::cout << sol.front() + 1 << "]" << std::endl;
    */

    return 0;
}