// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int countKeyChanges(string_view s) {
        int ans = 0;
        for(int i = 1; i < s.length(); ++i)
            if (tolower(s[i]) != tolower(s[i - 1]))
                ++ans;

        return ans;        
    }
};