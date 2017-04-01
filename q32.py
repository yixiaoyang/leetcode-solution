#!/usr/bin/python
# -*- coding: utf-8 -*-



def duang(s):
    if len(s) < 2:
        return 0

    str_stack = []
    idx_stack = []

    for i,c in enumerate(s):
        if i > 0 and len(str_stack) > 0:
            if c == ')' and str_stack[-1] == '(':
                str_stack.pop()
                idx_stack.pop()
                continue
        str_stack.append(c)
        idx_stack.append(i)

    if len(idx_stack) == 0:
        return len(s)

    idx_stack.append(len(s))
    max_len = 0
    for i,idx in enumerate(idx_stack):
        if i == 0:
            max_len = idx_stack[i]
            continue
        max_len = max(max_len, idx - idx_stack[i-1] - 1)


    return max_len


class Solution(object):
    def longestValidParentheses(self, s):
        return duang(s)

s = Solution()
#print(s.longestValidParentheses("(())(())"))
#print(s.longestValidParentheses("()"))
#print(s.longestValidParentheses(")(((((()())()()))()(()))("))
print(s.longestValidParentheses("(()"))
print(s.longestValidParentheses("())"))
