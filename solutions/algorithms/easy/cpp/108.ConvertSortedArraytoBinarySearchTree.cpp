#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& nums, int start, int end) {
        if (end + 1 - start < 1) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, start, mid - 1);
        root->right = buildTree(nums, mid + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        TreeNode* root = buildTree(nums, 0, nums.size() - 1);
        return root;
    }
};

void printTree(TreeNode* node) {
    if (node == nullptr)
        return;
    std::cout << node->val << " ";
    printTree(node->left);
    printTree(node->right);
}

int main() {
    std::vector<int> nums = { 1,3 };
    Solution solution;
    TreeNode* result = solution.sortedArrayToBST(nums);
    printTree(result);

    return 0;
}