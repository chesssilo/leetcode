// Time complexity: O(logn)
// Space complexity: O(logn)
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();

        unordered_map<int, int> cache;

        int low = 1;
        int high = length - 2;
        while (low != high) {
            int testIndex = (low + high) >> 1;

            int curr;
            if (cache.find(testIndex) != cache.end()) {
                curr = cache[testIndex];
            } else {
                curr = mountainArr.get(testIndex);
                cache[testIndex] = curr;
            }

            int next;
            if (cache.find(testIndex + 1) != cache.end()) {
                next = cache[testIndex + 1];
            } else {
                next = mountainArr.get(testIndex + 1);
                cache[testIndex + 1] = next;
            }

            if (curr < next) {
                if (curr == target) {
                    return testIndex;
                }
                if (next == target) {
                    return testIndex + 1;
                }
                low = testIndex + 1;
            } else {
                high = testIndex;
            }
        }

        int peakIndex = low;

        low = 0;
        high = peakIndex;
        while (low <= high) {
            int testIndex = (low + high) >> 1;

            int curr;
            if (cache.find(testIndex) != cache.end()) {
                curr = cache[testIndex];
            } else {
                curr = mountainArr.get(testIndex);
            }
                
            if (curr == target) {
                return testIndex;
            } else if (curr < target) {
                low = testIndex + 1;
            } else {
                high = testIndex - 1;
            }
        }

        low = peakIndex + 1;
        high = length - 1;
        while (low <= high) {
            int testIndex = (low + high) >> 1;

            int curr;
            if (cache.find(testIndex) != cache.end()) {
                curr = cache[testIndex];
            } else {
                curr = mountainArr.get(testIndex);
            }
                
            if (curr == target) {
                return testIndex;
            } else if (curr > target) {
                low = testIndex + 1;
            } else {
                high = testIndex - 1;
            }
        }

        return -1;
    }
}; 