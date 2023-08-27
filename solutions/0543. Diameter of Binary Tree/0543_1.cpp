// Time complexity: O(n)
// Space complexity: O(h)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root, ans);
        return ans;
    }

private:
    int height(TreeNode* node, int ans) {
        if (node == nullptr)
            return 0;

        int left_height = height(node->left, ans);
        int right_height = height(node->right, ans);
        ans = max(ans, left_height + right_height);
        
        return 1 + max(left_height, right_height);
    }
};