#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Approach: Optimal Approach
//Time complexity: O(n)
//Space complexity: O(1)
//Runtime 12ms Beats 16.53% Memory 11.8MB Beats 27.8%
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

void print(ListNode* head) {
    if (head != 0) {
        std::cout << head->val << " ";
        print(head->next);
    }
}

int main() {
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;

    Solution solution;
    auto result = solution.rotateRight(head, k);
    print(result);
   
	return 0;
}