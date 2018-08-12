class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        new_s = ""
        for char in s:
            if char.isalnum():
                new_s += char
        new_s = new_s.lower()
        print(new_s)
        i = 0
        j = len(new_s)-1
        while i < j:
            if new_s[i] != new_s[j]:
                return False
            i += 1
            j -= 1
        return True

sol = Solution()
s = input()
print(sol.isPalindrome(s))