// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int minimumTimeToInitialState(const string& word, int k) {
        int count = 0;
        string copy = word;
        do {
            copy = copy.substr(k) + string(k, '*');
            ++count;
        } while (!check(word, copy));
            
        return count;
    }
private:
    bool check(string_view word, string_view copy) {
        for (int i = 0; i < word.size(); ++i) {
            if (copy[i] != '*' && word[i] != copy[i]) {
                return false;
            }
        }
        return true;
    }    
};