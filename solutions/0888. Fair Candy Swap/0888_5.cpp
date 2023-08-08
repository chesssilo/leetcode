class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = 0;
        int sumBob = 0;
        
        sort(aliceSizes.begin(), aliceSizes.end());
        for (int item : aliceSizes) {
            sumAlice += item;
        }
        sort(bobSizes.begin(), bobSizes.end());
        for (int item : bobSizes) {
            sumBob += item;
        }
        assert((sumAlice - sumBob) % 2 == 0);
        int diff = ( sumAlice - sumBob) / 2;
        int b = 0;
        for (int i : aliceSizes) {
            int j = i - diff;
            while (b <(int)bobSizes.size() && bobSizes[b] < j) {
                b++;
            }
            if (b < (int)bobSizes.size() && bobSizes[b] == j) {
                return vector<int>{i, j};
            }
        }
        throw invalid_argument("no solution for given A and B");
    }
};