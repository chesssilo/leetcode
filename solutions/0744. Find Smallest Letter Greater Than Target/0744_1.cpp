// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char letter : letters) 
            if (letter > target) return letter;

        return letters[0];
    }
};