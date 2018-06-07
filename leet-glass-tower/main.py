class Solution:

    def __init__(self):
        pass

    def champagneTower(self, poured, query_row, query_glass):
        """
        :type poured: int
        :type query_row: int
        :type query_glass: int
        :rtype: float
        """

        A = [[0]*k for k in range(1, 102)]
        A[0][0] = poured
        for r in range(query_row+1):
            for c in range(r+1):
                q = (A[r][c] - 1)/2
                if q > 0:
                    A[r+1][c] += q
                    A[r+1][c+1] += q

        return min(1, A[query_row][query_glass])

if __name__ == "__main__":
    poured, query_row, query_glass = int(input()), int(input()), int(input())
    sol = Solution()
    res = sol.champagneTower(poured, query_row, query_glass)
    print(res)

        