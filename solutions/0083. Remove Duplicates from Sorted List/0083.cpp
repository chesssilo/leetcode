class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* curr = dummy;
        while (curr) {
            ListNode* next = curr->next;
            while (next && next->val == curr->val)
                next = next->next;
            curr->next = next;
            curr = next;
        }
        return dummy->next;
    }
};