class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            low = i + 1
            high = len(nums)-1
            while low < high:
                curr_sum = nums[i] + nums[low] + nums[high]
                if curr_sum > 0:
                    high -= 1
                elif curr_sum < 0:
                    low += 1
                else:
                    res.append([nums[i], nums[low], nums[high]])
                    while low < high and nums[low] == nums[low+1]:
                        low += 1
                    while low < high and nums[high] == nums[high-1]:
                        high -= 1
                    low += 1
                    high -= 1
        return res

nums = list(map(int, input().split(' ')))
sol = Solution()
print(sol.threeSum(nums))
            