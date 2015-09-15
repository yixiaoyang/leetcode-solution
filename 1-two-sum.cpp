/*
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the
target, where index1 must be less than index2. Please note that your returned answers (both
 index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include "includes.h"

using namespace std;

class TwoSumSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> eMaps;
        unordered_map<int,int>::iterator map_it;
        vector<int>::iterator vec_it;
        vector<int> res;
        int pos = 0;

        // map[num, position]
        function<void(int)> num2pos_lamba = [&eMaps,&pos](const int num){
            eMaps[num] = pos;
            pos++;
        };

        for_each( nums.begin(), nums.end(), num2pos_lamba);

        for(vec_it = nums.begin(), pos = 0;
            vec_it < nums.end();
            vec_it++ , pos++){
            map_it = eMaps.find(target-(*vec_it));
            if(map_it != eMaps.end()){
                if(pos > (*map_it).second){
                    res.push_back((*map_it).second+1);
                    res.push_back(pos+1);
                }else if(pos < (*map_it).second){
                    res.push_back(pos+1);
                    res.push_back((*map_it).second+1);
                }else{
                    continue;
                }
                cout << "index1=" << res[0] << ", index2=" << res[1] << endl;
                return res;
            }
        }
        return res;
    }
};

int main1()
{
    TwoSumSolution solu;
    vector<int> nums;
    int target = 6;

    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);

    solu.twoSum(nums,target);
    return 0;
}
