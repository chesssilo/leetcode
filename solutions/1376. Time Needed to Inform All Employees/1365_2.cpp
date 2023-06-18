// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> children;

        for (int i = 0; i < n; i++) {
            children[manager[i]].push_back(i);
        }

        stack<pair<int, int>> stk;
        int ans = 0;

        stk.push(make_pair(headID, 0));

        while (!stk.empty()) {
            pair<int, int> p = stk.top(); stk.pop();
            int node = p.first, curTime = p.second;

            ans = max(ans, curTime);

            for (int child : children[node]) {
                stk.push(make_pair(child, curTime + informTime[node]));
            }
        }
        return ans;
    }
};