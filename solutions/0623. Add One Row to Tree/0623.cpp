// Time complexity: O(n)
// Space complexity: O(h)
class Solution {
 public:
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1)
      return new TreeNode(val, root, nullptr);

    if (root == nullptr)
      return new TreeNode(val);    

    addRow(root, val, depth, 1);

    return root;    
  }
 private:
  void addRow(TreeNode* node, int val, int depth, int currDepth) {
    if (node == nullptr)
      return;

    if (currDepth == (depth - 1)) {
      node->left = new TreeNode(val, node->left, nullptr);
      node->right = new TreeNode(val, nullptr, node->right);
      return;
    }

    addRow(node->left, val, depth, currDepth + 1);
    addRow(node->right, val, depth, currDepth + 1);
  }    
};