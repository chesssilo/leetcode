// Time complexity: O(n⋅logn+m⋅logm)
// Space complexity: O(logm+logn)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ranges::sort(g);
        ranges::sort(s);

        int contentChildren = 0;
        int cookieIndex = 0;

        while(cookieIndex < s.size() && contentChildren < g.size()) {
            if (s[cookieIndex] >= g[contentChildren]) {
                ++contentChildren;
            }
            ++cookieIndex;
        }

        return contentChildren;
    }
};