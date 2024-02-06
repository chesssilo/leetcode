// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minimumTimeToInitialState(string_view word, int k) {
        int ans = 1;
        auto z = zFunction(word);
        for (; k * ans < word.length(); ++ans)
            if (z[k * ans] >= word.length() - k * ans)
                break;

        return ans;        
    }
private:
    vector<int> zFunction(string_view s) {
        int left = 0;
        int right = 0;
        vector<int> z(s.length());

        for (int i = 1; i < s.length(); ++i) {
            if (i < right)
                z[i] = min(right - i, z[i - left]);
            while (i + z[i] < s.length() && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] > right) {
                left = i;
                right = i + z[i];
            }        
        }

        return z;
    }    
};