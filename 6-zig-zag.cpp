#include "includes.h"

/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given
number of rows like this: (you may want to display this pattern in
a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

class ZigZagSolution {
public:
    static string convert(string s, int numRows) {
        int len = s.size();
        string res;
        const int groupBy = 2*numRows-2;

        int pos1 = 0;
        int pos2= 0;
        int start = 0;

        if(numRows == 1)
            return s;

        // row = 0
        for(pos1 = 0; pos1 < len; pos1+=groupBy)
            res.push_back(s.at(pos1));

        // row = (0,numRows-1)
        for(int row = 1; row < numRows-1; row++){
            for(start = 0; start < len; start+=groupBy){
                pos1 = start+row;
                pos2 = start+2*numRows-row-2;
                if(pos1 < len)
                    res.push_back(s.at(pos1));
                if((pos2 < len) && (pos1 != pos2))
                    res.push_back(s.at(pos2));
            }
        }

        for(pos1 = numRows-1; pos1 < len; pos1+=groupBy)
            res.push_back(s.at(pos1));

        return res;
    }
};

int main6()
{
    //convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR";
    //PAHNAPLSIIGYIR
    //PAHNAPLPIPGPYIYRY
    //string resTest("PAHNAPLSIIGYIR");
    //string res = ZigZagSolution::convert("PAYPALISHIRING", 3);
    string res = ZigZagSolution::convert("ABCDEF", 2);
    cout << res;
/*
    if(res != resTest)
        cout << "fail:" << res<< endl;
    else
        cout << "succ:" << res<< endl;
  */
  return 0;
}
