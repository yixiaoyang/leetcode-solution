/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
 */

#include "includes.h"

class IntReverseSolution {
public:
    // using string?
    static int reverse(int x) {
        const static int overflowInt = 0x7FFFFFFF;
        bool rising = (x >= 0);
        char buf[32];
        int res;
        string resStr;

        x = abs(x);

        sprintf(buf,"%d",x);
        string str(buf);
        sprintf(buf,"%d",overflowInt);
        string overflow(buf);

        for(int i = str.size()-1; i>=0; i--){
            resStr.push_back(str.at(i));
        }

        if(resStr.size() >= overflow.size())
            if(resStr > overflow)
                return 0;

        if(!rising)
            resStr.insert(0,"-");

        res = atoi(resStr.c_str());
        return res;
    }


    int reverse2(int x) {
        const static int overflowInt = 0x7FFFFFFF;
        long result = 0;           // Final result
        long op = x < 0 ? -1 : 1;  // Get the operator

        long tmp = abs((long)x);  // Avoid too many type conversions and work with positive number
        while (tmp) {             // When tmp is zero, stops
            result += tmp % 10;   // Get the last number
            result *= 10;
            tmp /= 10;
        }
        result /= 10;  // Remove the last zero

        return result > (long)overflowInt ? 0 : result * op;
    }
};

int main7()
{
    // overflow
    //cout << atoi("9646324351") << endl;
    cout << IntReverseSolution::reverse(-2147483648) << endl;
    return 0;
}

