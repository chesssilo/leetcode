// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
    int minDiff = INT_MAX;
    int prev = - 1;

    void inOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversal(root->left);
        if (prev >= 0) {
            minDiff = min(minDiff, (root->val - prev));
        }    
        prev = root->val;
        inOrderTraversal(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        inOrderTraversal(root);
        return minDiff;
    }
};