class Solution:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        for i in range(len(nums)):
            idx = abs(nums[i])-1
            if nums[idx] >= 0:
                nums[idx] = -nums[idx]
            else:
                res.append(idx+1)
        print(res)
        return res

nums = list(map(int, input().split(' ')))
sol = Solution()
sol.findDuplicates(nums)