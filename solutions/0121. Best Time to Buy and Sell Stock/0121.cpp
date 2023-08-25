// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int ans = 0;
        int prevMin = prices[0];
        
        for (int price : prices) {
            ans = max(ans, price - prevMin);
            prevMin = min(prevMin, price);
        }
        return ans; 
    }
};