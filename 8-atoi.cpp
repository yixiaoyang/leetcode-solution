#include "includes.h"

/*
"1234"
"-1234"
"+1234"

If no valid conversion could be performed, a zero value is returned.
If the correct value is out of the range of representable values,
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 */

class MyAtoiSolution {
public:
    static int myAtoi(string str) {
        // 2147483647
        const static int overflowInt = 0x7FFFFFFF;
        const static int overflowInt2 = 0x7FFFFFFF/10;

        char ch;
        bool isRising=true;
        int index = 0;
        int len = str.size();
        int res = 0;
        int tmp;

        if(str.size() < 1)
            return 0;

        // blanks
        for(index = 0; index < len; index++){
            ch = str.at(index);
            if(ch == ' ')
                continue;
            else
                break;
        }

        //symbol
        ch = str.at(index);
        if(ch == '-'){
            isRising = false;
            index++;
        }else if(ch == '+'){
            isRising = true;
            index++;
        }

        // digtals
        for(; index < len; index++){
            ch = str.at(index);
            if(ch >= '0' && ch <= '9')
                tmp = ch-'0';
            else{
                break;
            }

            if(res > overflowInt2){
                return isRising?overflowInt:(0-overflowInt-1);
            }

            res *= 10;

            // overflow
            if(isRising){
                if(overflowInt - res < tmp)
                    return overflowInt;
            }else{
                if(overflowInt - res < tmp-1)
                    return 0-overflowInt-1;
            }
            res += tmp;
        }

        return isRising?res:(0-res);
    }
};

int main8()
{
    cout << MyAtoiSolution::myAtoi("+1234") << endl;
    cout << MyAtoiSolution::myAtoi("-1234") << endl;
    cout << MyAtoiSolution::myAtoi("+2147483647") << endl;
    cout << MyAtoiSolution::myAtoi("-2147483647") << endl;
    cout << MyAtoiSolution::myAtoi("+2147483646") << endl;
    cout << MyAtoiSolution::myAtoi("-2147483646") << endl;

    // 10
    cout << MyAtoiSolution::myAtoi("  0010") << endl;

    // -12
    cout << MyAtoiSolution::myAtoi("  -0012a42") << endl;

    // 2147483647
    cout << MyAtoiSolution::myAtoi("2147483648") << endl;
    cout << MyAtoiSolution::myAtoi("-2147483648") << endl;
    cout << MyAtoiSolution::myAtoi("-2147483649") << endl;
    cout << MyAtoiSolution::myAtoi("-2147483649adddx") << endl;

    //
    int a = -2147483648;
    cout << "a=" << a<< endl;

    a = -0x7FFFFFFF;
    a-=1;
    cout << "a=" << a<< endl;

    a = 0xFFFFFFFF;
    cout << "a=" << a<< endl;

    a = 0x80000001;
    cout << "a=" << a<< endl;

    a = 0x80000000;
    cout << "a=" << a<< endl;
    return 0;
}
