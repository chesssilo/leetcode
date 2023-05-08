#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode(0);
        ListNode* current = res;

        while (true) {
            if (list1 == NULL) {
                current->next = list2;
                break;
            }

            if (list2 == NULL) {
                current->next = list1;
                break;
            } 
            
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }
        return res->next;
    }
};

int main() {
    ListNode l1 = ( 1, 2, 4 );
    ListNode l2 = ( 1, 3, 4 );
    Solution solution;
    solution.mergeTwoLists(&l1, &l2);

	return 0;
}