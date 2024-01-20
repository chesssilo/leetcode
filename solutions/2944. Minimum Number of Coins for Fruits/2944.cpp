// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        const int n = prices.size();
        int ans = INT_MAX;
        deque<pair<int, int>> minQ{{0, n}};

        for (int i = n - 1; i >= 0; --i) {
            while (!minQ.empty() && minQ.front().second > (i + 1) * 2)
                minQ.pop_front();
            ans = prices[i] + minQ.front().first;
            while (!minQ.empty() && minQ.back().first >= ans)
                minQ.pop_back();
            minQ.emplace_back(ans, i);
        }

        return ans;
    }
};