/*
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
//'*' Matches zero or more of the preceding element.
isMatch("aab", "c*a*b") → true
 */

#include "includes.h"

class ReMatchSolution {
public:
#if 0
    //The matching should cover the entire input string (not partial).
    static bool isMatch(string s, string p) {
        bool wild = false;

        int sPos = 0;
        int pPos = 0;
        int sLen = s.size();
        int pLen = p.size();
        char ch;
        unsigned int tmp = 0;

        while(pPos < pLen){
            if(sPos >= sLen)
                return true;

            ch = p.at(pPos);
            switch(ch){
            case '.':
                sPos++;
                break;
            case '*':
                wild = true;
                break;
            default:
                if(wild){
                    // find the first index from sPos
                    tmp = s.find_first_of(ch,sPos);
                    if(tmp ==  string::npos)
                        return false;
                    sPos = tmp+1;
                }else{
                    if(s.at(sPos) != ch)
                        return false;
                    sPos++;
                }
                wild = false;
                break;
            }

            pPos++;
        }

        if(wild){
            // "abcd" : "ab*" => true
            // "abcd" : "ab*." => true
            return true;
        }else{
            // "abcd" : "ab" => false
            if(sPos != sLen){
                return false;
            }
            // "abcd" : "ab*." => true
        }
        return true;
    }
#endif
#if 0
    //The matching should cover the entire input string (not partial).
    static bool isMatch(string s, string p) {
        char ch;
        char wildCh;
        int sPos = 0;
        int pPos = 0;
        const int sLen = s.size();
        const int pLen = p.size();
        int tmp = 0;

        if(p.size() == 0){
            if(s.size() == 0)
                return true;
            return false;
        }

        if(p.at(0) == '*')
            return false;

        while(pPos < pLen){
            ch = p.at(pPos);

            // aaa, aaab*, match
            // aaa, aaabb, mismatch
            if(sPos >= sLen){
                while(pPos < pLen){
                    if(ch == '*')
                        pPos++;
                    else{
                        if(pPos < pLen -1){
                            if(p.at(pPos+1) == '*'){
                                pPos = pPos+2;
                                continue;
                            }else{
                                return false;
                            }
                        }
                        return false;
                    }
                }
                return true;
            }

            switch(ch){
            case '.':
                sPos++;
                break;
            case '*':
                wildCh = p.at(pPos-1);
                if(wildCh == '.'){
                    // ".*"
                    if(pPos < pLen-1){
                        tmp = s.find_first_of(p.at(pPos+1),sPos);
                        if(tmp ==  string::npos)
                            return false;
                        else{
                            pPos = pPos+1;
                            sPos = tmp+1;
                            break;
                        }
                    }else
                        return true;
                }

                // find the last ch != wildCh
                tmp = pPos+1;
                while(tmp < pLen){
                    if(p.at(tmp) == wildCh)
                        tmp++;
                    else
                        break;
                }
                // swap p[pPos, tmp], "aa*aa" => "aaaa*"
                tmp -= 1;
                if(tmp != pPos){
                    p[pPos] = wildCh ;
                    p[tmp] = '*';
                    // pPos agiain
                    continue;
                }


                // aaaa, aa*a
                while(sPos < sLen){
                    if(s.at(sPos) == wildCh){
                        sPos++;
                    }else{
                        break;
                    }
                }
                break;
            default:
                if(ch == s.at(sPos)){
                    sPos++;
                }else{
                    if(pPos < pLen-1){
                        if(p.at(pPos+1) != '*'){
                            return false;
                        }else{
                            // * => zero pre ch
                            //sPos++;
                            pPos++;
                        }
                    }else{
                        // reach end
                        return false;
                    }
                }
                break;
            }

            pPos++;
        }

        if(sPos != sLen)
            return false;

        return true;
    }
#endif
    static bool c_isMatch(const char *s, const char *p) {
        //assert(s && p);
        if (*p == '\0') return *s == '\0';

        // next char is not '*': must match current character
        if (*(p+1) != '*') {
            //assert(*p != '*');
            return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }
        // next char is '*'
        while ((*p == *s) || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    }
    static bool isMatch(string s, string p) {
        return ReMatchSolution::c_isMatch(s.c_str(),p.c_str());
    }
};

int main10()
{
    bool result;
    struct TestCase{
        string s;
        string p;
        bool res;
        TestCase(string ss, string pp, bool r):s(ss),p(pp),res(r){}
    };

    struct TestCase cases[] = {
                TestCase("aa","a",false),
                TestCase("aa","aa",true),
                TestCase("aaa","aa",false),
                TestCase("aa","a*",true),
                TestCase("aa", ".*",true),
                TestCase("ab", ".*",true),
                TestCase("aab", "c*a*b",true),
                TestCase("aaa", "aaaa",false),
                TestCase("aaa", "aaaa*",true),
                TestCase("aaa", "aaaa*b",false),
                TestCase("ab", ".*c",false),
                TestCase("aaa", "a*a",true),
                TestCase("aaa", "ab*a",false),
                TestCase("aaa", "ab*a*c*a", true)
    };

    for(unsigned int index = 0; index <  sizeof(cases)/sizeof(cases[0]); index++){
        result = ReMatchSolution::isMatch(cases[index].s,cases[index].p);
        if(cases[index].res != result)
            cout << cases[index].s << ":" << cases[index].p << " => " << result << endl;
        else
            cout << ".";
    }

    return 0;
}
