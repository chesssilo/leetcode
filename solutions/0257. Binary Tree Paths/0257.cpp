// Time complexity: O(n)
// Space complexity: O(h)
class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    visit(root, "", ans);

    return ans;
  }
 private:
  void visit(TreeNode *node, string path, vector<string> &ans) {
    if (node == nullptr)
      return;

    if (node->left == nullptr && node->right == nullptr) {
      ans.push_back(path + to_string(node->val));
        return;
    }

    path += to_string(node->val) + "->";
    visit(node->left, path, ans);
    visit(node->right, path, ans);
  }
};