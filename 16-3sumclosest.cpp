#include "includes.h"
/*
Given an array S of n integers, find three integers in S such that the sum is closest to
a given number, target. Return the sum of the three integers. You may assume that each
input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

[3,-74,21,43,-94,-83,2,-97,-28,83,76,-4,17,95,62,5,-55,73,94,18,-32,79,-40,-60,-42,-10,23,43,71,3,40,64,-53,36,-18,-66,-20,-52,18,-96,-86,-45,19,16,-91,-90,-61,-92,-22,-26,-48,-24,-68,-95,19,-13,-61,-46,-45,3,14,98,-44,-54,49,40,-37,97,-72,-58,13,-27,28,21,1,40,-49,56,25,25,56,36,-27,31,56,21,-59,-44,89,-25,88,-72,0,-95,70,65,-84,52,66,-76,-71,91,-12,82,-98,56,-3,87,-54,-62,0,-15,9]
*/

#if 0
int threeSumClosest(int* nums, int numsSize, int target) {
}
#endif

class ThreeSumClosestSolution {
public:

    // O(n^3)
#if 0
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = 0;
        int minDistance = 0;
        int minDistanceSum = 0;
        const int count = nums.size();
        int tmp;
        sort(nums.begin(),nums.end());

        if(nums.size() < 3)
            return 0;

        minDistanceSum = nums[0] + nums[1] + nums[2];
        minDistance = abs(minDistanceSum-target);

        for (int aidx = 0; aidx < count; ++aidx)
        {
            for (int bidx = aidx+1; bidx < count; ++bidx)
            {
                for (int cidx = bidx+1; cidx < count; ++cidx)
                {
                    sum = nums[aidx] + nums[bidx] + nums[cidx];
                    tmp = abs(sum-target);
                    if(tmp < minDistance){
                        minDistance =tmp;
                        minDistanceSum = sum;
                    }

                    if(sum > 0 && sum > target + minDistance)
                        break;
                }
            }
        }

        return minDistanceSum;
    }
#endif

    int threeSumClosest(vector<int>& nums, int target) {
        int sum = 0;
        int minDistance = 0;
        int minDistanceSum = 0;
        const int count = nums.size();
        int tmp;
        int left;
        int right;

        if(nums.size() < 3)
            return 0;

        // 1. sort
        sort(nums.begin(),nums.end());

        minDistanceSum = nums[0] + nums[1] + nums[2];
        minDistance = abs(minDistanceSum-target);

        for (int aidx = 1; aidx < count-1; ++aidx)
        {
            left = 0;
            right = nums.size()-1;
            while(left < right ){
                if(left == aidx){
                   left++;
                   continue;
                }
                if(right == aidx){
                    right--;
                    continue;
                }

                sum = nums[aidx] + nums[left] + nums[right];
                tmp = sum - target;

                if(minDistance > abs(tmp)){
                    minDistance = abs(tmp);
                    minDistanceSum = sum;
                }

                if(tmp > 0){
                    right--;
                }else{
                    left++;
                }
            }
       }

        return minDistanceSum;
    }
};

int main()
{
    ThreeSumClosestSolution solu;
    //vector<int> nums = {-1,2,1,-4};
    int num = 0;
    vector<int> nums = {3,-74,21,43,-94,-83,2,-97,-28,83,76,-4,17,95,62,5,-55,73,94,18,-32,79,-40,-60,
                        -42,-10,23,43,71,3,40,64,-53,36,-18,-66,-20,-52,18,-96,-86,-45,19,16,-91,-90,
                        -61,-92,-22,-26,-48,-24,-68,-95,19,-13,-61,-46,-45,3,14,98,-44,-54,49,40,-37,
                        97,-72,-58,13,-27,28,21,1,40,-49,56,25,25,56,36,-27,31,56,21,-59,-44,89,-25,88,
                        -72,0,-95,70,65,-84,52,66,-76,-71,91,-12,82,-98,56,-3,87,-54,-62,0,-15,9};

    for(int i = 0; i < nums.size(); i++){
        num = nums[i];
        cout << num << "=> "  << solu.threeSumClosest(nums,num) << endl;
    }

    return 0;
}
