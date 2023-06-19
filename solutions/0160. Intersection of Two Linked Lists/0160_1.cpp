class Solution {
    int getLen(ListNode *a) {
        int len = 0;
        while (a != nullptr) {
            len++;
            a = a->next;
        }
        return len;
    }

    ListNode* shift(ListNode *a, int steps) {
        assert(steps >= 0);
        while (steps > 0) {
            a = a->next;
            steps--;
        }
        return a;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        ListNode* a = shift(headA, max(0, lenA - lenB));
        ListNode* b = shift(headB, max(0, lenB - lenA));
        while (true) {
            if (a == b) {
                return a;
            }
            a = a->next;
            b = b->next;
        }
    }
};