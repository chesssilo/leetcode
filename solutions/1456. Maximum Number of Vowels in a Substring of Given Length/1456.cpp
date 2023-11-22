// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxVowels(string_view s, int k) {
        int ans = 0;
        int maxi = 0;
        string kVowels = "aeiou";

        for (int i = 0; i < s.length(); ++i) {
            if (kVowels.find(s[i]) != string::npos) {
                maxi++;
            }
            if (i >= k && kVowels.find(s[i - k]) != string::npos) {
                maxi--;
            }
            ans = max(ans, maxi);
        }

        return ans;
    }
};