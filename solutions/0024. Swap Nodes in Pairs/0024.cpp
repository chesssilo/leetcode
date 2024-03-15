// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode* prevN = head;
    ListNode* nextN = head->next;

    prevN->next = swapPairs(head->next->next);
    nextN->next = prevN;

    return nextN;    
  }
};