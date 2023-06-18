class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        string str, temp;
        for (int i = 2; i <= n - 2; ++i) {
            int d = n;
            while (d > 0) {
                str.append(to_string(d % i));
                d = d / i;
            }
            temp = str;
            reverse(str.begin(), str.end());
            if (str == temp) {
                str.erase(str.begin(), str.end());
            }
            else
                return false;
        }
        return true;
    }
};