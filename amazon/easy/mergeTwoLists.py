class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        if not list1:
            return list2
        if not list2:
            return list1

        if list1.val < list2.val:
            newList = ListNode(list1.val)
            list1 = list1.next
        else:
            newList = ListNode(list2.val)
            list2 = list2.next

        ans = newList

        while list1 and list2:
            if list1.val < list2.val:
                newList.next = ListNode(list1.val)
                list1 = list1.next
            else:
                newList.next = ListNode(list2.val)
                list2 = list2.next
            newList = newList.next

        while list1:
            newList.next = ListNode(list1.val)
            list1 = list1.next

        while list2:
            newList.next = ListNode(list2.val)
            list2 = list2.next

        return ans