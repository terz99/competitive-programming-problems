class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        mat = [[0 for _ in range(n+2)] for _ in range(n+2)]
        for i in range(n+2):
            mat[0][i] = -1
            mat[n+1][i] = -1
            mat[i][0] = -1
            mat[i][n+1] = -1
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        di = 0
        cnt = 1
        i = 1
        j = 1
        while cnt <= n*n:
            mat[i][j] = cnt
            cnt += 1
            if mat[i + dx[di]][j + dy[di]] != 0:
                di += 1
                di = di%4
            i += dx[di]
            j += dy[di]
        res = []
        for i in range(1, n+1):
            res.append(mat[i][1:(n+1)])
        for i in range(n):
            print(res[i])
        return res

sol = Solution()
n = int(input())
sol.generateMatrix(n)
