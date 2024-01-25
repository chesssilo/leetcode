// Time complexity: O(∣s∣+∣a∣+∣b∣)
// Space complexity: O(∣s∣+∣a∣+∣b∣)
class Solution {
public:
    vector<int> beautifulIndices(string s, string_view a, string_view b, const int k) {
        vector<int> indicesOfA, indicesOfB, ans;
        
        for (int i = 0; i < s.size(); ++i) {
            string cur = s.substr(i, a.size());
            if (cur == a) indicesOfA.push_back(i);

            cur = s.substr(i, b.size());
            if (cur == b) indicesOfB.push_back(i);    
        }
        
        for (const int i : indicesOfA) {
            auto it = lower_bound(begin(indicesOfB), end(indicesOfB), i - k);
            if (it == end(indicesOfB)) continue;
            if (*it > i + k) continue;
            ans.push_back(i);
        }

        return ans;
    }
};