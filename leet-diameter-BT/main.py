# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def getDepth(self, root, depth):
        if root is None:
            return 0, depth
        totalLeft, left = self.getDepth(root.left, depth+1)
        totalRight, right = self.getDepth(root.right, depth+1)
        return max(totalLeft, totalRight, left+right), max(left, right)

    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        totalLeft, left = self.getDepth(root.left, 0)
        totalRight, right = self.getDepth(root.right, 0)
        return max(totalLeft, totalRight, left+right)