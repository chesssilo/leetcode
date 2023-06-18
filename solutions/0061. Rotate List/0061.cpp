// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        ListNode* newHead;
        ListNode* tail;
        newHead = tail = head;
        int size = 1;

        while (tail->next) {
            tail = tail->next;
            size++;
        }

        tail->next = head;
        k = k % size;

        for (int i = 0; i < size - k; i++) 
            tail = tail->next;

        newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};