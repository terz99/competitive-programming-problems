class Solution:
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        for i in range(len(s)):
            if(s[i] != s[ len(s) - i - 1 ]):
                return self.is_valid_palindrome(i, len(s) - i - 2, s) \
                or self.is_valid_palindrome(i+1, len(s) - i - 1, s)

        return True

    def is_valid_palindrome(self, lower, upper, s):
        while lower < upper:
            if s[lower] != s[upper]:
                return False
            lower += 1
            upper -= 1
        return True

sol = Solution()
s = input()
print(sol.validPalindrome(s))