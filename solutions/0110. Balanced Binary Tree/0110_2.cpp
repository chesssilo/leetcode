// Time complexity: O(n)
// Space complexity: O(h)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }

private:
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }  
        int leftH = getHeight(node->left);
        if (leftH == -1) {
            return -1;
        }
        int rightH = getHeight(node->right);
        if (rightH == -1) {
            return -1;
        }
        if (abs(leftH - rightH) > 1) {
            return -1;
        } else {
            return max(leftH, rightH) + 1;
        } 
    }
};