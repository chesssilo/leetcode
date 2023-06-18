// Time complexity: O(log⁡n)
// Space complexity: O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        size_t i = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        return (i == letters.size()) ? letters[0] : letters[i];
    }
};