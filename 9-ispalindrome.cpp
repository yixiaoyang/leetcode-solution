/*
Determine whether an integer is a palindrome. Do this without extra space.
 */


#include "includes.h"

class IsPalindromeSolution {
public:
    static bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x < 10)
            return true;
        if(x % 10 == 0)
            return false;

        int res = 0;
        int tmp = x;
        while(tmp > res){
            res *= 10;
            res += (tmp%10);
            tmp /= 10;
        }

        return ((res == tmp) || ((res /10)==tmp));
    }
};

int main9()
{
    int val[] = {
        1,12,22,2244,4224,123,123454321,1234543210,1234543211
    };

    for(unsigned int index = 0; index < sizeof(val)/sizeof(val[0]); index++)
        cout << val[index] << ":" <<IsPalindromeSolution::isPalindrome(val[index]) << endl;

    return 0;
}
