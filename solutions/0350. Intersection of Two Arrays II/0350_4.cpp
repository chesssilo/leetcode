// Time complexity: O(m + n)
// Space complexity: O(min(m,n))
class HashMap {
    const int FREE = -1;
    vector<int> keys;
    vector<int> values;
    
public:
    HashMap(size_t size)
        : keys(size + size / 2 + 1)
        , values(size + size / 2 + 1, FREE)
    {} 

    void inc(int key) {
        size_t h = key % keys.size();
        while (true) {
            if (values[h] == FREE) {
                keys[h] = key;
                values[h] = 1;
                return;
            }
            if (keys[h] == key) {
                values[h]++;
                return;
            }
            h++;
            if (h == values.size()) {
                h = 0;
            }
        }
    } 

    bool dec(int key) {
        size_t h = key % keys.size();
        while (true) {
            if (values[h] == FREE) {
                return false;
            }
            if (keys[h] == key) {
                if (values[h] > 0) {
                    values[h]--;
                    return true;
                } else {
                    assert(values[h] == 0);
                    return false;
                }
            }
            h++;
            if (h == values.size()) {
                h = 0;
            }
        }
    }      
};

class Solution {
public:
    vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) {
        const vector<int> &a = nums1.size() < nums2.size() ? nums1 : nums2;
        const vector<int> &b = nums1.size() < nums2.size() ? nums2 : nums1;
        HashMap count(a.size());
        for (int v : a) {
            count.inc(v);
        }
        vector<int> ans;
        for (int v : b) {
            if (count.dec(v)) {
               ans.push_back(v);
            }
        }
        return ans;
    }
};