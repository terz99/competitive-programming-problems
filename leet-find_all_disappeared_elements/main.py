class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for el in nums:
            idx = abs(el)-1
            if nums[idx] > 0:
                nums[idx] = -nums[idx]
        res = []
        for i in range(len(nums)):
            if nums[i] > 0:
                res.append(i+1)
        print(res)
        return res

nums = list(map(int, input().split()))
sol = Solution()
sol.findDisappearedNumbers(nums)