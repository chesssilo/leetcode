// Time complexity: O(n + m)
// Space complexity: O(1)
class Solution {
public:
    int getLastMoment(int n, const vector<int>& left, const vector<int>& right) {
        int ans = 0;
        for (int num : left) {
            ans = max(ans, num);
        }
        
        for (int num : right) {
            ans = max(ans, n - num);
        }
        
        return ans;
    }
};