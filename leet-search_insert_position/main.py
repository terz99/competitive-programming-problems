class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        low = 0
        high = len(nums)-1
        res = 0
        if target < nums[0]:
            return 0
        elif target > nums[-1]:
            return len(nums)
        while low <= high:
            mid = (low+high)//2
            if target <= nums[mid]:
                res = mid
                high = mid-1
            else:
                low = mid + 1
        return res
            