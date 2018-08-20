class Solution(object):

    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums:
            return [-1]*2

        l = 0
        r = len(nums)-1
        while l < r:
            mid = (l+r)//2
            if target < nums[mid]:
                r = mid - 1
            elif target > nums[mid]:
                l = mid + 1
            else:
                l = mid
        if l < 0 or l >= len(nums):
            return [-1]*2
        res = [l]
        l = 0
        r = len(nums)-1
        while l < r:
            mid = (l+r+1)//2
            if target < nums[mid]:
                r = mid - 1
            elif target > nums[mid]:
                l = mid + 1
            else:
                r = mid
        res.append(r)
        return res

nums = list(map(int, input().split()))
target = int(input())
sol = Solution()
print(sol.searchRange(nums, target))