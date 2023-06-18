class Solution {
	vector<int> result;

	void preorder(TreeNode* node) {
		if (!node) return;
		preorder(node->left);
		preorder(node->right);
		result.push_back(node->val);
	}

public:
	vector<int> postorderTraversal(TreeNode* root) {
		preorder(root);
		return result;
	}
};