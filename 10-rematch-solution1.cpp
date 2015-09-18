#include "includes.h"

#include <set>
#include <cstdio>
#include <cstring>
/*
    https://leetcode.com/problems/regular-expression-matching/
    Description:
        for each character in p, we scan the match list for it.
        e.g.
        s = aaaabbac
        p = ab*ac
        (index is 0-based)
        We always compare the next character in s to the index in the match list. the initial match list is {-1}
        the first character 'a', we have {0,1,2,3,6} as the 'a''s match list.
        then we scan b*, from the index exist in the last match list, but here we need the copy the last match list to the current match
        list first, because b* can be a null string.
        then we get { 0('a'),1('a'),2('a'),3('a'),4('b'),5('b'),6('a') } as b's match list
        then we scan the next character 'a''s match list, from the index that exist in the last match list, b's.
        we get { 1,2,3,6 }
        here we come to the last character 'c'.
        we only find { 7 }, because 6 is 'a' and 7 is 'c'.
        we trace the maximumId that we've reached, that is, 7, and now we've finished the p string.
        7 means we've finished the s string as well. So, Accept.
        If both pattern and s string are null, we Accept.

        The condition that we Reject:
        if a character doesn't match anything, its match list is null. we Reject.
        if we go through the whole p string, and the maximumId we can reach doesn't cover the whole s string, that means
        this pattern only matchs part of s string, we Reject.

        2015-09-13
*/
class Solution10Example {
public:
    bool match(char a, char b) {
        return b == '.' || a == b;}

    bool isMatch(char* s, char* p) {
        /*
           we use an array to log matching status as we move along
           arr[i] = 1 if and only if s.substr(0, i) matches the current regex
        */
        int sLen = strlen(s);
        bool arr[sLen+1];

        /*
            initially our regex is ""
            we set arr to [1, 0, 0, 0, 0, ...] because
            the only substring matches "" is s.substr(0, 0), which is an empty string
        */
        memset(arr+1, 0, sLen);
        *arr = 1;

        /* we scan through p to extend our regex and update arr */
        for(p; *p; p++) {

            /* let reg denote the previous regex, and c denote the next character (p[0]) */

            if(p[1] == '*') {
                /*
                    if we have a star,
                    then substr(0, i+1) matches reg+"c*" (new regex) in two cases:
                        1. substr(0, i+1) matches reg (a[i+1] = 1)
                        2. substr(0, i) matches reg (arr[i] = 1) and s[i] matches c
                */
                for(int i = 0; i < sLen; i++) {
                    arr[i+1] = arr[i+1] | (arr[i] & match(s[i], *p));}

                /* note: we need to skip the * as well */
                p++;
            }

            else {
                /*
                   if not a star, then substr(0, sLen-i) matches reg+"c" only if
                   substr(0, sLen-i-1) matches reg (arr[sLen-i-1]) and s[sLen-i-1] matches c
                */
                for(int i = 0; i < sLen; i++) {
                    arr[sLen-i] = arr[sLen-i-1] & match(s[sLen-i-1], *p);}

                /*
                    if we have any character not following by a star in p, then our regex cannot match ""
                    so we set arr[0] to 0
                */
                arr[0] = 0;}
        }

        /*
           our goal is to determine if s.substr(0, sLen) (which is s) matches p
           so we just return arr[sLen]
        */
        return arr[sLen];
    }
};
