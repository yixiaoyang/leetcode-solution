#include "includes.h"

using namespace std;

// Manacher
class LongestPalindromeSolution {
public:
    string longestPalindrome(string sStr){
        string pStr("#");
        string res;
        int pLen = convert(sStr,pStr);
        vector<int> table(pLen);

        int center = 2;
        int scopeL;
        int scopeR;
        int offset = 1;

        int tmpL;
        int tmpR;
        int tmpRMax;
        int centerMax;

        int max = 0;
        int maxPos = 0;

        table[0] = 0;
        table[1] = 1;
        maxPos = 1;
        max = 1;

        while(center < pLen){
            scopeL = center -offset;
            scopeR = center +offset;

            // pidx
            while(scopeL >= 0 && scopeR < pLen){
                if(pStr.at(scopeL) == pStr.at(scopeR)){
                    scopeL--;
                    scopeR++;
                    table[center]++;
                }else{
                    break;
                }
            }

            centerMax = center + table[center];
            if( table[center] > max ){
                maxPos = center;
                max = table[center];
            }

            // pidx+?
            for(tmpR = center+1; tmpR < scopeR; ){
                 tmpL = 2*center-tmpR;
                 tmpRMax = table[tmpL] + tmpR;
                 if( tmpRMax < centerMax ){
                     table[tmpR] = table[tmpL];
                     tmpR++;
                 }else{
                     table[tmpR] = centerMax - tmpR;
                     offset = table[tmpR]+1;
                     break;
                 }
            }

            // reset pIdx
            center = tmpR;
            //printVector(table);
        }

        res = sStr.substr(((maxPos-table[maxPos])>>1),table[maxPos]);
        cout << maxPos << ":" << table[maxPos] << ":" << res << endl;
        return res;
    }

    int convert(string &src, string& dst){
        int index;
        int len = src.size();

        //cout << "src:#-";
        for(index = 0; index < len; index++){
            dst.push_back(src.at(index));
            //cout << src.at(index) << " ";
            dst.append("#");
            //cout << "#"  << " ";
        }
        //cout << endl;
        return dst.size();
    }
private:
    void printVector(vector<int> &vec){
        cout << "res:";
        for(unsigned int i = 0; i < vec.size()-1; i++){
            cout << vec.at(i) << " ";
        }
        cout << endl;
        cout.flush();
    }
};

int main()
{
    string dst("#");
    string src("1232454232414211");
    string src2("12784487sad22s2f");
    string src3("a");
    string src4("b2");

    LongestPalindromeSolution solu;
    cout << solu.longestPalindrome(src3) << endl;
    cout << solu.longestPalindrome(src4) << endl;

    //cout << solu.convert(src,dst) << ": " << dst;
    return 0;
}
