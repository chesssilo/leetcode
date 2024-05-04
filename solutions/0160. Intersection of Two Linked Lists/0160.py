# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
    a = headA
    b = headB

    while a != b:
      a = a.next if a else headB
      b = b.next if b else headA

    return a    