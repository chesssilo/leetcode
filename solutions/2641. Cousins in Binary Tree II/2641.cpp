// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  TreeNode* replaceValueInTree(TreeNode* root) {
    calculateLevelSum(root, 0);
    replaceValueInTreeInternal(root, 0, 0);
    return root;
  }

 private:
  int levelSums[100000];

  void calculateLevelSum(TreeNode* node, int level) {
    if (node == nullptr)
      return;

    levelSums[level] += node->val;
    calculateLevelSum(node->left, level + 1);
    calculateLevelSum(node->right, level + 1);
  }

  void replaceValueInTreeInternal(TreeNode* node, int siblingSum, int level) {
    if (node == nullptr)
      return;

    int leftChildVal = node->left == nullptr ? 0 : node->left->val;
    int rightChildVal = node->right == nullptr ? 0 : node->right->val;

    if (level == 0 || level == 1)
      node->val = 0;
    else
      node->val = levelSums[level] - node->val - siblingSum;

    replaceValueInTreeInternal(node->left, rightChildVal, level + 1);
    replaceValueInTreeInternal(node->right, leftChildVal, level + 1);
  }
};