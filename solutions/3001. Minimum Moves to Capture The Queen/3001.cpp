// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e)
            return (c == a && (b < d && d < f || b > d && d > f)) ? 2 : 1;
        if (b == f)
            return (d == f && (a < c && c < e || a > c && c > e)) ? 2 : 1;
        if (c + d == e + f)
            return (a + b == c + d && (c < a && a < e || c > a && a > e)) ? 2 : 1;
        if (c - d == e - f)
            return (a - b == c - d && (c < a && a < e || c > a && a > e)) ? 2 : 1;
        return 2;
    }
};