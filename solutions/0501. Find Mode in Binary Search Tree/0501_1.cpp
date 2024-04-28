// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> countMap;
    int maxStreak = 0;
    
    traverse(root, countMap, maxStreak);
    
    vector<int> ans;
    for (const auto& pair : countMap)
      if (pair.second == maxStreak)
        ans.push_back(pair.first);
    
    return ans;
  }
  
 private:
  void traverse(TreeNode* node, unordered_map<int, int>& countMap, 
                int& maxStreak) {
    if (node == nullptr)
      return;
    
    ++countMap[node->val];
    maxStreak = max(maxStreak, countMap[node->val]);
    
    traverse(node->left, countMap, maxStreak);
    traverse(node->right, countMap, maxStreak);
  }
};