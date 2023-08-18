// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
    void visit(TreeNode* node, int &prev, bool &prevFilled, int &ans, bool &ansFilled) {
        if (node == nullptr) {
            return;
        }
        visit(node->left, prev, prevFilled, ans, ansFilled);
        if (prevFilled) {
            assert(node->val > prev);
            if(prev >= 0 || node->val <= INT_MAX + prev) {
                int diff = node->val - prev;
                ans = min(ans, diff);
                ansFilled = true;
            }
        }
        prev = node->val;
        prevFilled = true;
        visit(node->right, prev, prevFilled, ans, ansFilled);
    }

public:
    int minDiffInBST(TreeNode* root) {
        int prev = 0;
        bool prevFilled = false;
        int ans = INT_MAX;
        bool ansFilled = false;
        visit(root, prev, prevFilled, ans, ansFilled);
        if (!ansFilled) {
            throw overflow_error("answer greater than INT_MAX");
        }
        return ans;
    }  
};
