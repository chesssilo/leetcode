// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        int good = 0;
        int bad = n;

        while(bad > good + 1) {
            int mid = good +((bad - good) >> 1);
            if (isBadVersion(mid)) {
                bad = mid;
            } else {
                good = mid;
            }  
        }
        return bad;
    }
};