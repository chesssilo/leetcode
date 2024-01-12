// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool halvesAreAlike(string_view s) {
        string kVowels = "aeiuoAEIOU";
        int vowelsCount = 0, n = s.size();
        for(int i = 0;i < n; i++)
            if(kVowels.find_first_of(s[i]) != string::npos)
                vowelsCount = i < n / 2 ? vowelsCount + 1 : vowelsCount - 1;
            
        return vowelsCount == 0; 
    }
};