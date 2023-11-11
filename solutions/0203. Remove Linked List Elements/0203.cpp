// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            ListNode* t = head;
            head = head->next;
            delete t;
        }
        if (head == nullptr) {
            return head;
        }
        ListNode* cur = head;
        assert(cur->val != val);
        while (true) {
            assert(cur != nullptr);
            assert(cur->val != val);
            if (cur->next == nullptr) {
                return head;
            }
            if (cur->next->val == val) {
                ListNode* t = cur->next;
                cur->next = cur->next->next;
                delete t;
            } else {
                cur = cur->next;
            }
        }
    }
};