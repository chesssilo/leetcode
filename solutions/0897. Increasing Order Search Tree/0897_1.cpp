// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
    void visit(TreeNode* node, TreeNode*& result) {
        if (node == nullptr) {
            return;
        }
        visit(node->right, result);
        node->right = result;
        result = node;
        visit(node->left, result);
        node->left = nullptr; 
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* result = nullptr;
        visit(root,result);
        return result;
    }    
};