// Time complexity: O(min(mlogn,nlogm))
// Space complexity: O(min(m,n))
struct Pair {
    int num;
    int count;
};

class Solution {
public:
    vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) {
        const vector<int> &a = nums1.size() < nums2.size() ? nums1 : nums2;
        const vector<int> &b = nums1.size() < nums2.size() ? nums2 : nums1;
        vector<Pair> pairs;
        pairs.reserve(a.size());
        
        for (int v : a) {
            pairs.push_back(Pair{v, 1});
        }
        sort(pairs.begin(), pairs.end(), [](const Pair &left, const Pair &right) {
            return left.num < right.num;
        });
        int last = -1;
        for (int i = 0; i < (int)pairs.size(); i++) {
            if (last >= 0 && pairs[i].num == pairs[last].num) {
                pairs[last].count++;
            } else {
                last++;
                pairs[last] = pairs[i];
            }
        } 
        pairs.resize(last + 1);
        vector<int> ans;
        for (int v : b) {
            auto it = lower_bound(pairs.begin(), pairs.end(), v, [](const Pair &p, int v) {
                return p.num < v;
            });
            if (it != pairs.end() && it->num == v && it->count > 0) {
                ans.push_back(v);
                it->count--;
            }
        }
        return ans;
    }
};