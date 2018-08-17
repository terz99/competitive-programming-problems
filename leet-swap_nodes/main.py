# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):

    def __init__(self):
        self.prevN = None

    def swap(self, node1, node2):
        """
        :type node1: ListNode
        :type node2: ListNode
        :rtype: ListNode
        """
        node2.next = node1
        if self.prevN == None:
            self.prevN = node1
        else:
            self.prevN.next = node2
            self.prevN = node1
        return node1

    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head
        rHead = head.next

        curr = head.next
        prev = head
        while curr and prev:
            tmp = curr.next
            self.swap(prev, curr).next = tmp
            if tmp:
                curr = tmp.next
            prev = tmp
        return rHead
        