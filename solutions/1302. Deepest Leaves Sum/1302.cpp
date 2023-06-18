class Solution {
public:
	int deepestLeavesSum(TreeNode* root) {
		int sum = 0;
		queue<TreeNode*> q{ {root} };

		while (!q.empty()) {
			sum = 0;
			for (int i = q.size(); i > 0; --i) {
				TreeNode* node = q.front();
				q.pop();
				sum += node->val;
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
		}
		return sum;
	}
};