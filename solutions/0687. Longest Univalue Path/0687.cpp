
// Time complexity: O(n)
// Space complexity: O(h)
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        getUpPath(root, ans);
        return ans;    
    }
private:
    int getUpPath(TreeNode* node, int &ans) {
        if (node == nullptr) {
            return 0;
        }
        int leftH = getUpPath(node->left, ans);
        if (node->left != nullptr && node->left->val != node->val) {
            leftH = 0;
        }
        int rightH = getUpPath(node->right, ans);
        if (node->right != nullptr && node->right->val != node->val) {
            rightH = 0;
        }
        ans = max(ans,leftH + rightH);
        return 1 + max(leftH, rightH);
    }   
};