class Solution(object):

    def check(self, idx, strs, mid):
        word = strs[idx]
        for i in range(len(strs)):
            if idx == i:
                continue
            
            for j in range(mid+1):
                if word[j] != strs[i][j]:
                    return False
        return True

    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]
        minLen = 10**9
        idx = None
        for i in range(len(strs)):
            word = strs[i]
            if minLen > len(word):
                minLen = len(word)
                idx = i
        res = ""
        low = 0
        high = len(strs[idx])-1
        while low <= high:
            mid = (low+high)//2
            if self.check(idx, strs, mid):
                res = strs[idx][:mid+1]
                low = mid+1
            else:
                high = mid-1
        return res