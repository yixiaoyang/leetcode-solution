#include "includes.h"


class RomanNumberSolution{
public:
    static string intToRoman(int num) {
        string res;
        const int kvals[] = {
            1,4,5,9,10,40,50,90,
            100,400,500,900,1000
        };
        const char *kstr[]={
            "I","IV","V","IX","X","XL","L","XC",
            "C","CD","D","CM","M"
        };
        const int maxSize = sizeof(kvals)/sizeof(kvals[0]);
        int kPos = maxSize;
        while(num > 0){
            if(num >= kvals[kPos]){
                res.append(kstr[kPos]);
                num -= kvals[kPos];
            }else{
                kPos--;
            }
        }

        return res;
    }

    //Ⅰ（1）、V（5）、X（10）、L（50）、C（100）、D（500）、M（1000）
    static int romanToInt(string s) {
        const int slen = s.size();
        unsigned int sPos = 0;
        int res = 0;
        int tmp1 = 0;
        int tmp2 = 0;
        unordered_map<char,int> kmap;
        kmap['I'] = 1;
        kmap['V'] = 5;
        kmap['X'] = 10;
        kmap['L'] = 50;
        kmap['C'] = 100;
        kmap['D'] = 500;
        kmap['M'] = 1000;

        while(sPos < slen){
            tmp1 = kmap[s.at(sPos)];
            if(sPos < slen-1)
                tmp2 = kmap[s.at(sPos+1)];
            else
                tmp2 = 0;
            if(tmp1 >= tmp2){
                res += tmp1;
                sPos++;
            }else{
                res += tmp2-tmp1;
                sPos+=2;
            }
        }
        return res;
    }
};

int main11_12()
{
    typedef struct _TestCase{
        int num;
        string res;
        _TestCase(int n, string str):num(n),res(str){}
    }TestCase;

    TestCase testCases[] = {
        TestCase(3999,"MMMCMXCIX"),
        TestCase(2000,"MM"),
        TestCase(1990,"MCMXC"),
        TestCase(1984,"MCMLXXXIV"),
        TestCase(1976,"MCMLXXVI"),
        TestCase(1984,"MCMLXXXIV"),
        TestCase(1976,"MCMLXXVI"),
        TestCase(1500,"MD"),
        TestCase(1400,"MCD"),
        TestCase(1000,"M"),
        TestCase(999,"CMXCIX"),

        TestCase(999,"CMXCIX"),
        TestCase(600,"DC"),
        TestCase(800,"DCCC"),

        TestCase(98,"XCVIII"),
        TestCase(65,"LXV")
    };

#if 0
    string res;

    for(unsigned int index = 0; index < sizeof(testCases)/sizeof(testCases[0]); index++){
        res = RomanNumberSolution::intToRoman(testCases[index].num);
        if(res != testCases[index].res){
            cout << testCases[index].num << "=>" << res << ", except: "<< testCases[index].res << endl;
        }else{
            cout << "." << endl;
        }
    }
#else
    int num;
    //num = RomanNumberSolution::romanToInt(string("XCVIII"));
    for(unsigned int index = 0; index < sizeof(testCases)/sizeof(testCases[0]); index++){
        num = RomanNumberSolution::romanToInt(testCases[index].res);
        if(num != testCases[index].num){
            cout << testCases[index].res << "=>" << num << ", except: "<< testCases[index].num << endl;
        }else{
            cout << "." << endl;
        }
    }
#endif
    return 0;
}
