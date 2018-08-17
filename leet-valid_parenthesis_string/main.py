class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        count = 0
        for i in range(len(s)):
            if s[i] == '(' or s[i] == '*':
                count += 1
            if s[i] == ')':
                count -= 1
            if count < 0:
                return False
        count = 0
        for i in range(len(s)-1, -1, -1):
            if s[i] == ')' or s[i] == '*':
                count += 1
            if s[i] == '(':
                count -= 1
            if count < 0:
                return False
        return True