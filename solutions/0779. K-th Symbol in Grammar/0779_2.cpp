// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int kthGrammar(int n, int k) {
        return recursion(n, k);
    }
private:
    int recursion(int n, int k) {
        if (n == 1) {
            return 0;
        }

        int totalElements = pow(2, (n - 1));
        int halfElements = totalElements / 2;

        if (k > halfElements) {
            return 1 - kthGrammar(n, k - halfElements);
        }

        return recursion(n - 1, k);
    }
};