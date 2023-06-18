class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        
        for (vector<int>& temp : accounts) {
            int sum = 0;
            for (int& value : temp) {
                sum += value;
            }
            if (sum > maxWealth)
                maxWealth = sum;
        }
        return maxWealth;
    }
};