class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = 0;
        int sumBob = 0;
        for (int item : aliceSizes) {
            sumAlice += item;
        }
        for (int item : bobSizes) {
            sumBob += item;
        }

        for (int i : aliceSizes) {
            for (int j : bobSizes) {
                if (sumAlice - i + j == sumBob - j + i) {
                    return vector<int>{i, j};
                }
            }
        }
        throw 1;
    }
};