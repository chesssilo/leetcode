// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:	
	TreeNode* increasingBST(TreeNode* root) {
    TreeNode* current = root;
    TreeNode* parent = nullptr;
    TreeNode* result = nullptr;
    while(true) {
      if (current == nullptr) {
        if (parent == nullptr) {
          return result;
      	} else {
          assert(parent != nullptr);
          current = parent;
          parent = parent->right;
          current->right = nullptr;
        }
      } else {
        assert(current != nullptr);
        if (current->right != nullptr) {
          TreeNode *tmp = current->right;
          current->right = parent;
          parent =current;
          current = tmp;
        } else {
          assert(current->right == nullptr);
          current->right = result;
          result = current;
          current = current->left;
          result->left = nullptr;
        }
      }
    }    
  }    
};