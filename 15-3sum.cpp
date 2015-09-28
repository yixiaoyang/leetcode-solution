#include "includes.h"

/*
Given an array S of n integers, are there elements a, b, c in S such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},
    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

tips:
1. 暴力枚举 O(n^2)复杂度



Submission Result: Wrong Answer
Input: [3,0,-2,-1,1,2]
Output: [[-2,0,2],[-1,0,1],[-2,-1,3],[-2,-1,3]]
Expected: [-2,0,2],[-1,0,1]],[[-2,-1,3]
 */

class ThreeSumSolution {
public:
#if 0
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> postiveNums;
        vector<int> negativeNums;
        bool ifZeroExised = false;
        int max = 0;
        int min = 0;
        // classify and sort
        for(unsigned int index = 0; index < nums.size(); index++){
            if(nums[index] > 0){
                if(nums[index] > max){
                    postiveNums.push_back(nums[index]);
                    max = nums[index];
                }else{
                    postiveNums.insert(postiveNums.begin(),nums[index]);
                }
            }else if(nums[index] < 0){
                if(nums[index] < min){
                    negativeNums.push_back(nums[index]);
                    min = nums[index];
                }else{
                    negativeNums.insert(negativeNums.begin(),nums[index]);
                }
            }else{
                ifZeroExised = true;
            }
        }

        // 2 postive nums + 1 negative num

        // 1 postive nums + 2 negative num

        // 1 postive nums + 1 negative num + 0

    }
#endif
#if 0
    static vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> posMap;
        unordered_set<int> negMap;
        unordered_set<int> posDumpMap;
        unordered_set<int> negDumpMap;
        unordered_set<int>::iterator tmpIt;
        std::pair<unordered_set<int>::iterator, bool> setRet;

        int tmp = 0;
        vector<int> tmpVec(3);

        int zeroCnt = 0;

        // classify and mapped
        for(unsigned int index = 0; index < nums.size(); index++){
            if(nums[index] > 0){
                setRet = posMap.insert(nums[index]);
                if(!setRet.second)
                    posDumpMap.insert(nums[index]);
            }else if(nums[index] < 0){
                setRet=negMap.insert(nums[index]);
                if(!setRet.second)
                    negDumpMap.insert(nums[index]);
            }else{
                zeroCnt++;
            }
        }

        for(unordered_set<int>::iterator posIdx = posMap.begin(); posIdx != posMap.end(); posIdx++){
            for(unordered_set<int>::iterator negIdx = negMap.begin(); negIdx != negMap.end(); negIdx++){
                tmp = 0-((*posIdx) + (*negIdx));
                if(tmp > 0){
                    if(tmp == *posIdx){
                        tmpIt=posDumpMap.find(tmp);
                        if(tmpIt == posDumpMap.end()){
                            continue;
                        }
                    }else{
                        tmpIt = posMap.find(tmp);
                        if(tmpIt == posMap.end()){
                            continue;
                        }
                    }
                    tmpVec[0] = *negIdx;
                    tmpVec[1] = (*tmpIt) <= (*posIdx) ?(*tmpIt) : (*posIdx);
                    tmpVec[2] = (*tmpIt) <= (*posIdx) ?(*posIdx) : (*tmpIt);
                    res.push_back(tmpVec);
                }else if(tmp < 0){
                    if(tmp == *negIdx){
                        tmpIt=negDumpMap.find(tmp);
                        if(tmpIt == negDumpMap.end()){
                            continue;
                        }
                    }else{
                        tmpIt = negMap.find(tmp);
                        if(tmpIt == negMap.end()){
                            continue;
                        }
                    }
                    tmpVec[0] = (*tmpIt) <= (*negIdx) ?(*tmpIt) : (*negIdx);
                    tmpVec[1] = (*tmpIt) <= (*negIdx) ?(*negIdx) : (*tmpIt);
                    tmpVec[2] = *posIdx;

                    res.push_back(tmpVec);
                }else{
                    if(zeroCnt){
                        tmpVec[0] = *negIdx;
                        tmpVec[1] = 0;
                        tmpVec[2] = *posIdx;
                        res.push_back(tmpVec);
                    }
                    continue;
                }
            }
        }

        for

        if(zeroCnt >= 3){
            tmpVec[0] = 0;
            tmpVec[1] = 0;
            tmpVec[2] = 0;
            res.push_back(tmpVec);
        }

        return res;
    }
#endif
    // a < b
    void add2Res(vector<int>& tmp, int a, int b, int c)
    {
        if(c < a){
            tmp[0] = c;
            tmp[1] = a;
            tmp[2] = b;
        }else if( c > b){
            tmp[0] = a;
            tmp[1] = b;
            tmp[2] = c;
        }else{
            tmp[0] = a;
            tmp[1] = c;
            tmp[2] = b;
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> tmp(3);
        int c = 0;
        unsigned int cidx;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(unsigned int aidx = 0 ; aidx < nums.size(); aidx++){
            if(aidx > 0){
                if(nums[aidx] == nums[aidx-1])
                    continue;
            }
            for(unsigned int bidx = aidx+1 ; bidx < nums.size(); bidx++){
                if(bidx > (aidx+1)){
                    if(nums[bidx] == nums[bidx-1])
                        continue;
                }

                c = 0-(nums[aidx]+nums[bidx]);
                if(c >= 0){
                    cidx = nums.size()-1;
                    while(cidx > bidx && nums[cidx] > c)
                        cidx --;
                    if(c == nums[cidx] && cidx != bidx){
                        // add (a,b,c)
                        add2Res(tmp,nums[aidx],nums[bidx],c);
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
};

int main15()
{
    ThreeSumSolution solu;
    //Input: [3,0,-2,-1,1,2]
    //Output: [[-2,0,2],[-1,0,1],[-2,-1,3],[-2,-1,3]]
    //Expected: [-2,0,2],[-1,0,1]],[[-2,-1,3]
    //vector<int> nums = {-1,0,1,2,-1,-4};
    //vector<int> nums = {3,0,0,-2,1,2,-2,-1,1,2};

    vector<int> nums = {0,0,0};
    vector<vector<int>> res = solu.threeSum(nums);

    for(unsigned int i = 0 ; i < res.size(); i++){
        for(unsigned int j = 0 ; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
