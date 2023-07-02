// Time complexity: O(log⁡n)
// Space complexity: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1, mid;

        while (left < right) {
            mid = (left + right) / 2;
            if (arr[mid] < arr[mid + 1]) 
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};