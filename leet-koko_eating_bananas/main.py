class Solution:
    def minEatingSpeed(self, piles, H):
        """
        :type piles: List[int]
        :type H: int
        :rtype: int
        """
        high = 0
        low = 1
        high = max(piles)
        res = 0
        while low <= high:
            mid = (low+high)//2
            curr = 0
            for el in piles:
                curr += el//mid
                if el%mid != 0:
                    curr += 1
            if curr > H:
                low = mid + 1
            else:
                res = mid
                high = mid - 1
        return res

piles = list(map(int, input().split()))
H = int(input())
sol = Solution()
print(sol.minEatingSpeed(piles, H))