// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* oldRoot) {
        Node* root = convert(oldRoot, nullptr, nullptr);
        return findMax(root, nullptr);
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

    void visit(Node* node, Node* parent, int dist, int &maxDist) {
        if (node == nullptr)
            return;
        if (dist > maxDist) {
            maxDist = dist;
        }
        for (Node* next : node->next) {
            if (next != parent) 
                visit(next, node, dist + 1, maxDist);
        } 
    }

    int findMax(Node* node, Node* parent) {
        if (node == nullptr)
            return 0;
        int maxDist = 0;
        visit(node, nullptr, 0, maxDist);
        for (Node* next : node->next) {
            if (next != parent) 
                maxDist = max(maxDist, findMax(next, node));
        }
        return maxDist;  
    }
}; 