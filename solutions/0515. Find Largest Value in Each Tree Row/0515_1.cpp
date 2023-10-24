// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        }

        vector<int> ans;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int curLength = queue.size();
            int curMax = INT_MIN;

            for (int i = 0; i < curLength; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                curMax = max(curMax, node->val);

                if (node->left) {
                    queue.push(node->left);
                }

                if (node->right) {
                    queue.push(node->right);
                }
            }

            ans.push_back(curMax);
        }
        
        return ans;
    }
};