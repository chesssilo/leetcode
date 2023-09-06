// Time complexity: O(n+k)
// Space complexity: O(k)
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, const int k) {
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
            ListNode* part = cur;
            for (int j = 0; j < width + (i < rem ? 1 : 0) - 1; ++j) 
                if (cur != nullptr) cur = cur->next;
            
            if (cur != nullptr) {
                ListNode* prev = cur;
                cur = cur->next;
                prev->next = nullptr;
            }
            ans[i] = part;
        }
        return ans;
    }
};