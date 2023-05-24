#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* make_list(std::vector<int> v) {
    ListNode* head = new ListNode(v[0]);
    for (int i = 1; i < v.size(); i++) {
        ListNode* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new ListNode(v[i]);
    }
    return head;
}

void print_list(ListNode* head) {
    ListNode* ptr = head;
    std::cout << "[";
    while (ptr) {
        std::cout << ptr->val << ", ";
        ptr = ptr->next;
    }
    std::cout << "]" << std::endl;
}

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

int main() {
    Solution solution;
    std::vector<int> v = { 1, 1, 2, 3, 3, 3, 4, 5, 5 };
    ListNode* head = make_list(v);
    print_list(solution.deleteDuplicates(head));

    return 0;
}