#!/usr/bin/python
# -*- coding: utf-8 -*-

'''
只要当前序列中的'('多于')'即合法

def duang(left_n, right_n, max_n, base=''):
    if left_n == max_n:
        base += ')'*(max_n-right_n)
        return(base)

    if left_n > right_n:
        duang(left_n+1, right_n, max_n, base+'(')
        duang(left_n, right_n+1, max_n, base+')')

    elif left_n == right_n:
        duang(left_n+1, right_n, max_n, base+'(')
'''
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.result = []
        self.duang(0,0,n)
        return (self.result)

    '''
    只要当前序列中的'('多于')'即合法
    '''
    def duang(self, left_n, right_n, max_n, base=''):
        if left_n == max_n:
            base += ')'*(max_n-right_n)
            self.result.append(base)
            return

        if left_n > right_n:
            self.duang(left_n+1, right_n, max_n, base+'(')
            self.duang(left_n, right_n+1, max_n, base+')')

        elif left_n == right_n:
            self.duang(left_n+1, right_n, max_n, base+'(')

s = Solution()
s.generateParenthesis(3)
