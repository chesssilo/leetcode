// Time complexity: O(n+k)
// Space complexity: O(max(n,k))
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cur = head;
        int n = 0;
        while (cur != nullptr) {
            cur = cur->next;
            n++;
        }

        int width = n / k, rem = n % k;
        vector<ListNode*> ans(k, nullptr);
        cur = head;
        for (int i = 0; i < k; ++i) {
            ListNode* part = new ListNode(0);
            ListNode* write = part;
            for (int j = 0; j < width + (i < rem ? 1 : 0); ++j) {
                write = write->next = new ListNode(cur->val);
                if (cur != nullptr) cur = cur->next;
            }
            ans[i] = part->next;      
        }
        return ans;
    }
};