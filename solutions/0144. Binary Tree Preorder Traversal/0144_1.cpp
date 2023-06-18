class Solution {
	vector<int> result;

	void preorder(TreeNode* node) {
		if (!node) return;
		result.push_back(node->val);
		preorder(node->left);
		preorder(node->right);
	}

public:
	vector<int> preorderTraversal(TreeNode* root) {
		preorder(root);
		return result;
	}
};