class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = 0;
        int sumBob = 0;
        unordered_set<int> BobValues;
        for (int item : aliceSizes) {
            sumAlice += item;
        }
        for (int item : bobSizes) {
            sumBob += item;
            BobValues.insert(item);
        }
        assert((sumAlice - sumBob) % 2 == 0);
        int diff = ( sumAlice - sumBob) / 2;
        for (int i : aliceSizes) {
            int j = i - diff;
            if (BobValues.count(j) > 0) {
              return vector<int>{i, j};
            }
        }
        throw invalid_argument("no solution for given A and B");
    }
};