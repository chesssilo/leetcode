// Time complexity: O(n)
// Space complexity: O(h)
class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return false;
		} 
		if (root->left == nullptr && root->right == nullptr) {
			return root->val == targetSum;
		} else {
			return 
				hasPathSum(root->left, targetSum - root->val) || 
				hasPathSum(root->right, targetSum - root->val);
		}
	}
};