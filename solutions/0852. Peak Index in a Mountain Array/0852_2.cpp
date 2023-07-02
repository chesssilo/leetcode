// Time complexity: O(log⁡n)
// Space complexity: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1, mid;

        while (start < end) {
            mid = (start + end) / 2;
            if (arr[mid] < arr[mid + 1]) 
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
};