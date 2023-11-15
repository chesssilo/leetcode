// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        while(true) {
            if (head == nullptr) {
                return false;
            }
            auto [it, inserted] = visited.insert(head);
            if (!inserted) {
                return true;
            }
            head = head->next;
        }
    }
};