// Time complexity: O(n)
// Space complexity: O(h)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        if (root->val > low) {
            sum += rangeSumBST(root->left, low, high);
        }
        if (root->val < high) {
            sum += rangeSumBST(root->right, low, high);
        }
        if (low <= root->val && root->val <= high) {
            sum += root->val;
        }
        return sum;
    }
};