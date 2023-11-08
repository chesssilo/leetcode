// Time complexity: O(1)
// Space complexity: O(1)
public class Solution {
    public bool IsReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int minStep = Math.Max(Math.Abs(sx - fx), Math.Abs(sy - fy));
        return minStep == 0 ? t != 1 : minStep <= t;
    }
}