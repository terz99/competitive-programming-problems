class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        counter = dict()
        for el in nums:
            if el in counter:
                counter[el] += 1
            else:
                counter[el] = 1

        tmp = []
        for key in counter.keys():
            counter[key] -= 1
            if (target - key) in counter and counter[target - key] != 0:
                tmp.append(key)
                tmp.append(target - key)
                break
        
        j = 0
        res = []
        for i in range(len(nums)):
            if j == 2:
                break
            if nums[i] in tmp:
                res.append(i)
                j += 1
        return res

nums = list(map(int, input().split(' ')))
target = int(input())
sol = Solution()
print(sol.twoSum(nums, target))