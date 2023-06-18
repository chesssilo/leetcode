class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        vector<int> ans;

        stk.push(cur);

        do {
            cur = stk.top();

            TreeNode* tmp = cur ? cur->left : NULL;
            while (tmp) {
                stk.push(tmp);
                tmp = tmp->left;
            }

            cur = stk.top(); stk.pop();
            if (cur) ans.push_back(cur->val);

            if (stk.size() > 0) stk.top()->left = NULL;

            if (cur && cur->right) stk.push(cur->right);
        } while (!stk.empty());
        
        return ans;
    }
};