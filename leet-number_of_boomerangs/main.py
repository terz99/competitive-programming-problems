from math import sqrt

class Solution:

    def dist(self, p1, p2):
        return sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)

    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        n = len(points)
        res = 0
        for i in range(n):
            counter = dict()
            for j in range(n):
                if i == j: continue
                d = self.dist(points[i], points[j])
                if d in counter:
                    counter[d] += 1
                else:
                    counter[d] = 1
            for val in counter.values():
                if val >= 2:
                    res += val*(val-1)
        return res

n = int(input())
points = []
for i in range(n):
    pts = list(map(float, input().split()))
    points.append(pts)
sol = Solution()
print(sol.numberOfBoomerangs(points))
                    