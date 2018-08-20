class Solution(object):

    def search(self, low, high, nums, target):
        """
        :type low: int
        :type high: int
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        while low <= high:
            mid = (low+high)//2
            if nums[mid] == target:
                return mid
            elif target < nums[mid]:
                high = mid - 1
            else:
                low = mid + 1
        return -1

    def find_start(self, i, nums, target):
        """
        :type i: int
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        previ = i
        l = 0
        r = i-1
        while i > 0 and nums[i-1] == target:
            previ = i
            i = self.search(l, r, nums, target)
            r = i-1
        
        if i == -1:
            return previ
        return i

    def find_end(self, i, nums, target):
        """
        :type i: int
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        previ = i
        l = i+1
        r = len(nums)-1
        while i < len(nums)-1 and nums[i+1] == target:
            previ = i
            i = self.search(l, r, nums, target)
            l = i+1
        if i == -1:
            return previ
        return i

    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) == 0:
            return [-1]*2
        
        i = self.search(0, len(nums)-1, nums, target)
        if i == -1:
            return [-1]*2
        
        start = self.find_start(i, nums, target)
        end = self.find_end(i, nums, target)

        return [start, end]