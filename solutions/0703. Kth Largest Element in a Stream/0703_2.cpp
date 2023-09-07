// Time complexity: O(nlogk)
// Space complexity: O(k)
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> topK;
    int k;

public:
    KthLargest(int k, const vector<int> &nums) : k(k) {
        for (int num : nums) {
            topK.push(num);
            if (topK.size() > k) {
                topK.pop();
            }
        }
    }

    int add(int val) {
        if (topK.size() == k && val <= topK.top())
            return topK.top();
        topK.push(val);
        if (topK.size() > k)
            topK.pop();

        assert(topK.size() == k);  
        return topK.top();
    }
};