// Time complexity: O(n)
// Space complexity: O(logn)
class Solution {
public:
  TreeNode* convertBST(TreeNode* root) {
    int totalSum = 0;
    int prev = 0;
    int count =0;
    convert(root, totalSum, prev, count);
    return root;
  }

private:  
  void convert(TreeNode* node, int &totalSum, int &prev, int &count) {
    if (node == nullptr) {
      return;
    }
    convert(node->right, totalSum, prev, count);
    if (node->val == prev) {
      count++;
    } else {
      totalSum += prev * count;
      count = 1;
      prev = node->val;
    }
    node->val += totalSum;
    convert(node->left, totalSum, prev, count);
  }    
};