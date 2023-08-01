// Time Complexity: O(T1+T2)
// Space Complexity: O(T1+T2)

class Solution {
    void getLeaves(TreeNode* node, vector<int> &leaves) {
        if (node == nullptr) {
            return;
        }
        if (node->left == nullptr && node->right == nullptr) {
            leaves.push_back(node->val);
            return;
        }
        getLeaves(node->left, leaves);
        getLeaves(node->right, leaves);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        getLeaves(root1, leaves1);
        vector<int> leaves2;
        getLeaves(root2, leaves2);
        return leaves1 == leaves2;
    }
};