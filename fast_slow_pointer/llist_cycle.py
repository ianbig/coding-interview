# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # create a set, each time a node is visted add to list
        # if node is already in set, there is circle
        record = set()

        ptr = head
        while ptr != None:
            if ptr in record:
                return True
            record.add(ptr)
            ptr = ptr.next
        return False
