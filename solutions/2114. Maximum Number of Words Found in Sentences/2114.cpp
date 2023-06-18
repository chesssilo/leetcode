class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int wordCount = 0;

        for (int i = 0; i < sentences.size(); i++) {
            int tempCount = 1;
            for (int j = 0; j < sentences[i].length(); j++) {
                if (sentences[i][j] == ' ')
                    tempCount += 1;
            }
            if (tempCount > wordCount) wordCount = tempCount;
        }
        return wordCount;
    }
};