from typing import Optional

# im doing this in c++ my brain cant comprehend linked lists in python
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        ans = Optional[ListNode]
        new_list = Optional[ListNode]

        while list1.next and list2.next:
            if list1.val < list2.val:
                new_list.val = list1.val
                list1 = list1.next

                if not ans:
                    ans = list1
            else:
                ans.append(list2)
                list2.next
