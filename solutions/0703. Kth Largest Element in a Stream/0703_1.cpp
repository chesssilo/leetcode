// Time complexity: O(nlogk)
// Space complexity: O(k)
class KthLargest {
    multiset<int> topK;
    int k;

public:
    KthLargest(int k, const vector<int> &nums) : k(k) {
        for (int num : nums) {
            topK.insert(num);
            if (topK.size() > k) {
                topK.erase(topK.begin());
            }
        }
    }

    int add(int val) {
        if (topK.size() == k && val <= *topK.begin())
            return *topK.begin();
        topK.insert(val);
        if (topK.size() > k)
            topK.erase(topK.begin());

        assert(topK.size() == k);  
        return *topK.begin();
    }
};