// Time complexity: O(logn)
// Space complexity: O(1)
public class Solution : VersionControl {
    public int FirstBadVersion(int n) {
        int good = 0;
        int bad = n;

        while (bad > good + 1) {
            int mid = good + ((bad - good) / 2);
            if (IsBadVersion(mid)) {
                bad = mid;
            } else {
                good = mid;
            }
        }
        return bad;
    }
}