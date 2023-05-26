#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> stk;
        TreeNode* cur = root;
        std::vector<int> ans;

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

int main() {
	
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

    Solution solution;
    auto result = solution.inorderTraversal(root);

    for (int i : result)
        std::cout << i << std::endl;
}