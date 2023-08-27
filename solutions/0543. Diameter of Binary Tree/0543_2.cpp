// Time complexity: O(n)
// Space complexity: O(n)
struct Node {
    Node* next[3];

    Node(Node *n1, Node *n2, Node *n3)
        : next{n1, n2, n3}
    {}    
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* oldRoot) {
        Node* root = convert(oldRoot, nullptr, nullptr);
        Node* endpoint1 = nullptr;
        int maxDist = 0;
        visit(root, nullptr, 0, endpoint1, maxDist);
        Node* endpoint2 = nullptr;
        int ans = 0;
        visit(endpoint1, nullptr, 0 , endpoint2, ans);
        return ans;
    } 

private:
    Node* convert(TreeNode* oldNode,TreeNode* oldParent, Node* newParent) {
        if (oldNode == nullptr)
            return nullptr;
        Node* newNode = new Node(newParent, nullptr, nullptr);
        newNode->next[1] = convert(oldNode->left, oldNode, newNode);
        newNode->next[2] = convert(oldNode->right, oldNode, newNode);
        return newNode;  
    }

    void visit(Node* node, Node* parent, int dist, Node* &farthest, int &maxDist) {
        if (node == nullptr)
            return;
        if (dist > maxDist) {
            maxDist = dist;
            farthest = node;
        }
        for (Node* next : node->next) {
            if (next != parent) 
                visit(next, node, dist + 1, farthest, maxDist);
        } 
    }
};       