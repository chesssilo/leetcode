class IntSet {
    vector<int> a;
public:
    IntSet(int capacity)
        : a(capacity * 2, 0)
    {
    }

    void insert(int value) {
        assert(value > 0);
        int pos = value % (int)a.size();
        while(true) {
            if (a[pos] == value) {
                return;
            }
            if (a[pos] == 0) {
                a[pos] = value;
                return;
            }
            pos = (pos + 1) % (int)a.size();
        }
    }

    int count(int value) const {
        if (value <= 0) {
            return 0;
        }
        int pos = value % (int)a.size();
        while(true) {
            if (a[pos] == value) {
                return 1;
            }
            if (a[pos] == 0) {
                return 0;
            }
            pos = (pos + 1) % (int)a.size();
        }
    }
};

class Solution {
public:
    vector<int> fairCandySwap(const vector<int>& aliceSizes, const vector<int>& bobSizes) {
        int sumAlice = 0;
        int sumBob = 0;
        IntSet BobValues(bobSizes.size());
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