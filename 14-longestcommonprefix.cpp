#include "includes.h"

class LongCommonPrefixSolution{
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size() == 0)
            return res;

        res = strs[0];
        for(unsigned int index = 1; index < strs.size(); index++){
            commonPrefix(strs[index],res);
        }

        return res;
    }

    void commonPrefix(string& src, string& prefix)
    {
        for(unsigned int index = 0; index < prefix.size(); index++){
            if( index >= src.size() || src[index] != prefix[index]){
                prefix = prefix.substr(0,index);
                cout << prefix << endl;
                break;
            }
        }
    }
};

int main14()
{
    LongCommonPrefixSolution solu;
    vector<string> srcVec;
    //srcVec.push_back(string("aa"));
    //srcVec.push_back(string("a"));
    srcVec.push_back(string("1235423"));
    srcVec.push_back(string("1234353"));
    srcVec.push_back(string("12435"));
    if(solu.longestCommonPrefix(srcVec) == string("12")){
        cout << "." << endl;
    }else{
        cout << "X" << endl;
    }

    return 0;
}
