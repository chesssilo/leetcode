// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push(make_pair(p, q));
        while (!st.empty()) {
            auto pair = st.top();
            st.pop();
            TreeNode* first = pair.first;
            TreeNode* second = pair.second;
            if (first == nullptr && second == nullptr) {
                continue;
            }
            if (first == nullptr || second == nullptr) {
                return false;
            }
            if (first->val != second->val) {
                return false;
            }
            st.push(make_pair(first->left, second->left));
            st.push(make_pair(first->right, second->right));
        }
        return true;  
    }
};