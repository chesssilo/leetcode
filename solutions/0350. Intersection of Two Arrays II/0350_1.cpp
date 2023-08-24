// Time complexity: O(m + n)
// Space complexity: O(min(m,n))
class Solution {
public:
    vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) {
        const vector<int> &a = nums1.size() < nums2.size() ? nums1 : nums2;
        const vector<int> &b = nums1.size() < nums2.size() ? nums2 : nums1;
        unordered_map<int,int> count;
        for (int v : a) {
            count[v]++;
        }
        vector<int> ans;
        for (int v : b) {
            auto it = count.find(v);
            if (it != count.end() && it->second > 0) {
                ans.push_back(v);
                it->second--;
            }
        }
        return ans;
    }
};