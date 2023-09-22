# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        curr = head.next
        h = head
        h.next = None
        while curr!=None:
            temp = curr
            curr = curr.next
            px = None
            x = h
            while (x!=None and x.val < temp.val):
                px = x
                x = x.next
            if px!=None:
                px.next = temp
            else:
                h = temp
            temp.next = x
        return h