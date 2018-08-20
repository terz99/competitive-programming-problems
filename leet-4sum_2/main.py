import collections

class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        ab = collections.Counter(a+b for a in A for b in B)
        return sum(ab[-c-d] for c in C for d in D)


A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
D = list(map(int, input().split()))
sol = Solution()
print(sol.fourSumCount(A, B, C, D))
