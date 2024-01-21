// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    int beautifulSubstrings(string_view s, const int k) {
        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            int vowels = 0, consonants = 0;
            for (int j = i; j < n; ++j) {
                if (isVowel(s[j]))
                    ++vowels;
                else 
                    ++consonants;

                if (vowels == consonants && (vowels * consonants) % k == 0)
                    ++ans;        
            }
        }

        return ans;       
    }
private:
    bool isVowel(const char &c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }     
};