// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while (left < right) {
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                ++left;
            }
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                --right;
            }
            swap(s[left++], s[right--]);
        }

        return s;
    }
};