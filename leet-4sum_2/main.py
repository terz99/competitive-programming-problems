import collections

class Solution(object):

    def to_num_count(self, A):
        """
        :type A: int
        :rtype: dict(int, int)
        """
        ret = {}
        for a in A:
            if a not in ret:
                ret[a] = 0
            ret[a] += 1
        return ret

    def threeSumCount(self, A, B, num_sum):
        """
        :type A: dict(int, int)
        :type B: dict(int, int)
        :type num_sum: int
        :rtype: int
        """
        count = 0
        for i in A:
            next_sum = num_sum - i
            if next_sum in B:
                count += B[next_sum]*A[i]
        return count

    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        A = self.to_num_count(A)
        B = self.to_num_count(B)
        C = self.to_num_count(C)
        D = self.to_num_count(D)

        cd = {}
        for c in C:
            for d in D:
                if c + d not in cd:
                    cd[c + d] = 0
                cd[c + d] += C[c]*D[d]

        count = 0
        for i in A:
            count += self.threeSumCount(B, cd, -i) * A[i]
        return count

