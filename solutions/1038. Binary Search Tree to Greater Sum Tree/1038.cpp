// Time complexity: O(n)
// Space complexity: O(h)
class Solution {
 public:
  TreeNode* bstToGst(TreeNode* root) {
    int pref = 0;

    function<void(TreeNode*)> reversedInorder = [&](TreeNode* root) {
      if (root == nullptr)
        return;

      reversedInorder(root->right);

      root->val += pref;
      pref = root->val;

      reversedInorder(root->left);
    };

    reversedInorder(root);
    return root;
  }
};