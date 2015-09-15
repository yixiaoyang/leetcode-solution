/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include "includes.h"

#if 0
// Memory Limit Exceeded
class SubstringSolution {
public:
    int lengthOfLongestSubstring(string s) {
        return do_lengthOfLongestSubstring(s,0);
    }

    unsigned int do_lengthOfLongestSubstring(string str, int startIdx){
        unordered_map<char,int> chMap;
        unordered_map<char,int>::iterator chMapIt;
        unsigned int preIdx = 0;
        unsigned int len = 0;

        for(int index = 0; index < startIdx; index++){
            chMap[str.at(index)] = index;
        }

        for(unsigned int index = startIdx; index != str.size(); index++){
            chMapIt = chMap.find(str.at(index));
            if(chMapIt != chMap.end()){
                preIdx = (*chMapIt).second;
                len = do_lengthOfLongestSubstring(str.substr(preIdx+1,str.size()-preIdx-1), index-preIdx);
                return len > index? len: index;
            }else{
                chMap[str.at(index)] = index;
            }
        }

        return chMap.size();
    }
};
#else
class SubstringSolution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_map<char,int> chMap;
        unordered_map<char,int>::iterator chMapIt;
        unsigned int maxLen = 0;
        unsigned int delStartIdx = 0;
        unsigned int preIdx = 0;

        for(unsigned int index = 0; index != str.size(); index++){
            chMapIt = chMap.find(str.at(index));
            if(chMapIt != chMap.end()){
                maxLen = chMap.size() > maxLen ? chMap.size(): maxLen;
                preIdx = (*chMapIt).second;
                for(unsigned int delIndex = delStartIdx; delIndex < preIdx; delIndex++){
                    chMap.erase(str[delIndex]);
                }
                delStartIdx = preIdx+1;
                chMap[str.at(index)] = index;
            }else{
                chMap[str.at(index)] = index;
            }
        }
        maxLen = chMap.size() > maxLen ? chMap.size(): maxLen;
        return maxLen;
    }
};
#endif
int main3()
{
    SubstringSolution solu;
    string str = string("do_leng234thmbzdOf23lengthOfLongestSubstring(strLo4ngestSu3bssada34234tring");
    cout << solu.lengthOfLongestSubstring(str);
    return 0;
}
