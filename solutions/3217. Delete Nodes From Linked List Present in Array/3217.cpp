// Time complexity: O(n+m)
// Space complexity: O(n)
class Solution {
 public:
  ListNode* modifiedList(const vector<int>& nums, ListNode* head) {
    ListNode dummy(0, head);
    unordered_set<int> numsSet{nums.begin(), nums.end()};

    for (ListNode* curr = &dummy; curr->next != nullptr;)
      if (numsSet.contains(curr->next->val)) {
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
      } else {
        curr = curr->next;
      }

    return dummy.next;
  }
};