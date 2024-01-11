// Time complexity: O(n)
// Space complexity: O(h)
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
private:
    int dfs(TreeNode* root, int mini, int maxi) {
        if (root == nullptr) {
            return 0;
        }
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        const int left = dfs(root->left, mini, maxi);
        const int right = dfs(root->right, mini, maxi);

        return max({maxi - mini, left, right});
    }
};