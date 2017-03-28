#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class ValidStringSolution {
public:
    bool isValid(string s) {
        struct CharNode{
            bool isLeft;
            char anotherChar;
            CharNode(bool is_left=true, char another=')') : isLeft(is_left),anotherChar(another){}
        };

        stack<char> left;
        char ch;

        CharNode node;


        if (s.size() == 0){
            return true;
        }

        unordered_map<char,CharNode> chMap;
        unordered_map<char,CharNode>::iterator itMap;

        chMap['('] = CharNode(true,')');
        chMap['{'] = CharNode(true,'}');
        chMap['['] = CharNode(true,']');
        chMap[')'] = CharNode(false,'(');
        chMap['}'] = CharNode(false,'{');
        chMap[']'] = CharNode(false,'[');

        for(unsigned int i = 0; i < s.size(); i++){
            itMap = chMap.find(s[i]);
            if(itMap == chMap.end())
                return false;
            node = (*itMap).second;
            if(node.isLeft){
                left.push(s[i]);
            }else{
                if(left.empty())
                    return false;
                ch = left.top();
                if(ch != node.anotherChar)
                    return false;
                else
                    left.pop();
            }
        }

        return left.size() == 0;
    }
};

int main()
{
    ValidStringSolution solu;
    string testCase[]= {
        "(){}[]",
        "()",
        "({[]})",
        "({[])",
        "(",
        "({[(){}}{{}]})",
        "]"
    };

    for(unsigned int i = 0; i < sizeof(testCase)/sizeof(testCase[0]); i++){
        cout << testCase[i] << ":" << solu.isValid(testCase[i]) << endl;
    }

    return 0;
}
