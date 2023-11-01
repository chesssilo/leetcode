// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> values;
        dfs(root, values);
        
        int maxStreak = 0;
        int currStreak = 0;
        int currNum = 0;
        vector<int> ans;
        
        for (int num : values) {
            if (num == currNum) {
                currStreak++;
            } else {
                currStreak = 1;
                currNum = num;
            }
            
            if (currStreak > maxStreak) {
                ans = {};
                maxStreak = currStreak;
            }
            
            if (currStreak == maxStreak) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
    
    void dfs(TreeNode* node, vector<int>& values) {
        if (node == nullptr) {
            return;
        }
        
        dfs(node->left, values);
        values.push_back(node->val);
        dfs(node->right, values);
    }
};