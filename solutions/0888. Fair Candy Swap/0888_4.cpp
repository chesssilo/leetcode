class Solution {
public:
    vector<int> fairCandySwap(const vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = 0;
        int sumBob = 0;
        
        for (int item : aliceSizes) {
            sumAlice += item;
        }
        sort(bobSizes.begin(), bobSizes.end());
        for (int item : bobSizes) {
            sumBob += item;
        }
        assert((sumAlice - sumBob) % 2 == 0);
        int diff = ( sumAlice - sumBob) / 2;
        for (int i : aliceSizes) {
            int j = i - diff;
            if (binary_search(bobSizes.begin(), bobSizes.end(), j)) {
              return vector<int>{i, j};
            }
        }
        throw invalid_argument("no solution for given A and B");
    }
};