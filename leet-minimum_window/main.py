class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if len(t) > len(s):
            return ""

        target = dict()
        for char in t:
            if char in target:
                target[char] += 1
            else:
                target[char] = 1
        
        counter = dict()
        left = 0
        minLen = len(s) + 1
        count = 0
        i = 0
        result = ""
        for char in s:

            if char in target:
                if char in counter:
                    if counter[char] < target[char]:
                        count += 1
                    counter[char] += 1
                else:
                    counter[char] = 1
                    count += 1

            if count == len(t):

                sc = s[left]
                while sc not in counter or counter[sc] > target[sc]:
                    if sc in counter and counter[sc] > target[sc]:
                        counter[sc] -= 1
                    left += 1
                    sc = s[left]
                if i - left + 1 < minLen:
                    result = s[left:i+1]
                    minLen = i - left + 1
            i += 1 
        
        return result

sol = Solution()
s = input()
t = input()
print(sol.minWindow(s, t))
        