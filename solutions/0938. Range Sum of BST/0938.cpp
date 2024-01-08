// Time complexity: O(n)
// Space complexity: O(h)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }

        return root->val + rangeSumBST(root->right, low, high) + 
               rangeSumBST(root->left, low, high);
    }
};