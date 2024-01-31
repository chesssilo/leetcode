// Time complexity : O(n)
// Space complexity : O(n)
class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> stack;

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                const int index = stack.top();
                stack.pop();
                ans[index] = i - index;
            }
            stack.push(i);
        }

        return ans;
    }
};