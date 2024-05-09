// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> count;

    inorder(root, count);

    int max_count = 0;
    for (const auto& [val, freq] : count)
      max_count = max(max_count, freq);

    vector<int> ans;
    for (const auto& [val, freq] : count)
      if (freq == max_count)
        ans.push_back(val);

    return ans;
  }

 private:
  void inorder(TreeNode* node, unordered_map<int, int>& count) {
    if (node == nullptr)
      return;

    inorder(node->left, count);
    ++count[node->val];
    inorder(node->right, count);
  }
};