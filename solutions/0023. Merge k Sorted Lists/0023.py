# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        while lists and len(lists) != 0:
            tmp = []
            for i in range(0, len(lists), 2):
                left = lists[i]
                right = lists[i+1] if i+1 < len(lists) else None
                tmp.append(self.merge(left, right))
            lists = tmp 
            if len(lists) == 1:
                return lists[0]

    def merge(self, list1, list2):
        dummy = tail = ListNode()

        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next 
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        tail.next = list1 or list2

        return dummy.next