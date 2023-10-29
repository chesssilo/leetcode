// Time complexity: O(log(buckets))
// Space complexity: O(1)
public class Solution {
    public int PoorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tests = minutesToTest / minutesToDie;
        int pigs = 0;
        
        while (Math.Pow(tests + 1, pigs) < buckets)
        {
            pigs++;
        }
        
        return pigs;
    }
}