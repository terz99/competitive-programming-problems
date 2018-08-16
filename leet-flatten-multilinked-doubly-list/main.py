
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child

class Solution(object):

    def flatten_util(self, parent, head):
        """
        :type parent: Node
        :type head: Node
        :rtype: Node
        """
        curr = head
        while True:
            if curr.child:
                curr = self.flatten_util(curr, curr.child)
            if curr.next:
                curr = curr.next
            else:
                break
        curr.next = parent.next
        if parent.next:
            parent.next.prev = curr
        parent.next = head
        head.prev = parent
        parent.child = None
        return head

    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        curr = head
        while curr:
            if curr.child:
                curr = self.flatten_util(curr, curr.child)
            curr = curr.next
        return head

