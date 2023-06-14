// Time complexity: O(n⋅log⁡n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> nodeValues;

    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        nodeValues.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);

        sort(nodeValues.begin(), nodeValues.end());
        int minDifference = INT_MAX;
        for (int i = 1; i < nodeValues.size(); i++) {
            minDifference = min(minDifference, nodeValues[i] - nodeValues[i - 1]);
        }
        return minDifference;
    }
};