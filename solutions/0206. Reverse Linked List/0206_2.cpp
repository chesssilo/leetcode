// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* revers = nullptr;

    while (head) {
      ListNode* next = head->next;
      head->next = revers;
      revers = head;
      head = next;
    }
    return revers;
  }
};