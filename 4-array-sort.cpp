/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity
should be O(log (m+n)).
 */

#include "includes.h"

class ArraySortSolution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int size = nums1.size()+nums2.size();
        bool single = size%2;
        int midIndx = size >> 1;
        int midVal = 0;

        vector<int>::iterator pos1 = nums1.begin();
        vector<int>::iterator pos2 = nums2.begin();

        vector<int>::iterator pos;
        for(int index = 0; index < midIndx; index++){
            if(pos1 != nums1.end() && pos2 != nums2.end()){
                if((*pos1) < (*pos2)){
                    midVal = (*pos1);
                    pos = pos1;
                    pos1++;
                }else{
                    midVal = (*pos2);
                    pos = pos2;
                    pos2++;
                }
            }else{
                if(pos1 == nums1.end()){
                    pos2 += midIndx-index;
                    pos = pos2;
                    break;
                }
                if(pos2 == nums2.end()){
                    pos1 += midIndx-index;
                    pos = pos1;
                    break;
                }
            }
        }

        midVal = (*pos);
        if(single){
            return midVal;
        }

        if(pos1 == nums1.end()){
            return ((double)(midVal + (*pos2)))/2;
        }else if(pos2 == nums2.end()){
            return ((double)(midVal + (*pos1)))/2;
        }else{
            return ((double)(midVal + (*pos)))/2;
        }
    }
};

int main4()
{
    ArraySortSolution solu;
    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(2);
    nums1.push_back(6);
    nums1.push_back(9);
    nums2.push_back(1);
    nums2.push_back(3);
    nums2.push_back(7);

    cout << solu.findMedianSortedArrays(nums1,nums2);
    return 0;
}
