// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> inorderNodes;

    void inorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }

        inorderTraversal(node->left);
        inorderNodes.push_back(node->val);
        inorderTraversal(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);

        int minDifference = INT_MAX;
        for (int i = 1; i < inorderNodes.size(); i++) {
            minDifference = min(minDifference, inorderNodes[i] - inorderNodes[i - 1]);
        }
        return minDifference;
    }
};