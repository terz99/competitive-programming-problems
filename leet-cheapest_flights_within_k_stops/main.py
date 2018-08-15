from heapq import heapify, heappush, heappop

class Solution:
    def findCheapestPrice(self, n, flights, src, dst, K):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type K: int
        :rtype: int
        """
        edges = [[] for _ in range(n)]
        for edge in flights:
            edges[edge[0]].append((edge[1], edge[2]))
        vis = [-1 for _ in range(n)]
        q = [(0, src, 0)]
        heapify(q)
        while q:
            curr = heappop(q)
            vis[curr[1]] = curr[0]
            if curr[1] == dst:
                break
            if curr[2] > K:
                continue
            for edge in edges[curr[1]]:
                heappush(q, (curr[0] + edge[1], edge[0], curr[2]+1))
        return vis[dst]

n = int(input())
flights = []
for _ in range(n):
    inp = list(map(int, input().split()[:3]))
    flights.append(inp)
src = int(input())
dst = int(input())
k = int(input())
sol = Solution()
print(sol.findCheapestPrice(n, flights, src, dst, k))



            
        