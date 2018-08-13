class Solution:
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counter = dict()
        for el in nums:
            if el in counter:
                counter[el] += 1
            else:
                counter[el] = 1
        nums = list(set(nums))
        res = 0
        for el in nums:
            if (el + 1) in counter:
                res = max(res, counter[el] + counter[el+1])
        return res

nums = list(map(int, input().split(' ')))
sol = Solution()
print(sol.findLHS(nums))