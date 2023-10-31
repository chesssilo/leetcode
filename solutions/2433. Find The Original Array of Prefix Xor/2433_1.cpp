// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> findArray(const vector<int>& pref) {
        vector<int> arr;

        arr.push_back(pref[0]);
        for (int i = 1; i < pref.size(); ++i) {
            arr.push_back(pref[i] ^ pref[i - 1]);
        }

        return arr;
    }
};