// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    int pivotInteger(int n) {
        int sumRight = 0;

        for (int j = n; j >= 1; j--) {
            sumRight += j;
            int sumLeft = 0;
            for (int i = 1; i <= j; i++) {
                sumLeft += i;  
            }
            if (sumLeft == sumRight) {
                return j;
                break;
            }
        }
        return -1;
    }
};