// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode prehead;
        ListNode* node = l1;
        prehead.next = node;
        int sum = 0;
        while (node) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            node->val = sum % 10;
            sum /= 10;
            if (!l1) {
                if (l2) {
                    node->next = l2;
                }
                else if (sum == 1) {
                    ListNode* newNode = new ListNode(sum);
                    node->next = newNode;
                }
            }
            node = node->next;
        }
        return prehead.next;
    }
};