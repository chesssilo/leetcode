#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        return isSymmetricHelper(root->left, root->right);
    }

    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;

        if (!left || !right || left->val != right->val)
            return false;

        return isSymmetricHelper(left->left, right->right) &&
            isSymmetricHelper(left->right, right->left);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(3);

    Solution solution;
    bool result = solution.isSymmetric(root);
    std::cout << result << std::endl;

	return 0;
}  