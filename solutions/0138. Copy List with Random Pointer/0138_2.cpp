// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        Node* cur = head;
        while (cur) {
            Node* new_node = new Node(cur->val);
            new_node->next = cur->next;
            cur->next = new_node;
            cur = new_node->next;
        }

        cur = head;
        while (cur) {
            if (cur->random) 
                cur->next->random = cur->random->next;
            
            cur = cur->next->next;
        }

        cur = head;
        Node* new_head = head->next;
        Node* new_cur = new_head;
        while (cur) {
            cur->next = cur->next->next;
            if (new_cur->next) 
                new_cur->next = new_cur->next->next;
            
            cur = cur->next;
            new_cur = new_cur->next;
        }

        return new_head;
    }
};