class Solution:

    def in_interval(self, house, heater, mid):
        return (heater - mid) <= house <= (heater + mid)

    def check(self, houses, heaters, mid):
        i = 0
        j = 0
        vis = [False for _ in range(len(houses))]
        while i < len(heaters):
            while j < len(houses) and self.in_interval(houses[j], heaters[i], mid):
                vis[j] = True
                j += 1
            i += 1
        if False in vis:
            return False
        return True

    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        houses.sort()
        heaters.sort()
        high = 10**9
        low = 0
        res = 0
        while low <= high:
            mid = (low+high)//2
            if self.check(houses, heaters, mid):
                res = mid
                high = mid - 1
            else:
                low = mid + 1
        return res

