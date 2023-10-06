// Time complexity: O(n)
// Space complexity: O(h+n)
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mpp;
        mpp[0]=1;
        return solve(root, targetSum, 0, mpp);
    }
private:
    int solve(TreeNode* root, int k, long long sum, unordered_map<long long, int>& mpp){
        if(root == nullptr)
            return 0;
            
        sum+=root->val;
        
        int count = mpp[sum - k];
        mpp[sum]++;
        
        int left=solve(root->left, k, sum, mpp);
        int right=solve(root->right, k, sum, mpp);
        
        mpp[sum]--;
        sum-=root->val;
        return count+left+right;
    }
};