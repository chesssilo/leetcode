// Time complexity: O((n+m)*logn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> difference;
        difference[0] = 0;
        
        for (vector<int>& flower : flowers) {
            difference[flower[0]]++;
            difference[flower[1] + 1]--;
        }
        
        vector<int> positions;
        vector<int> prefix;
        int curr = 0;
        for (auto& pair : difference) {
            positions.push_back(pair.first);
            curr += pair.second;
            prefix.push_back(curr);
        }
        
        vector<int> ans;
        for (int person : people) {
            int i = upper_bound(positions.begin(), positions.end(), person) - positions.begin() - 1;
            ans.push_back(prefix[i]);
        }
        
        return ans;
    }
};