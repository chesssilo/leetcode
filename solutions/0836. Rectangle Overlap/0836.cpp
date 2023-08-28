// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    bool isRectangleOverlap(const vector<int>& rec1, const vector<int>& rec2) {
        return rec1[0] < rec2[2] && rec2[0] < rec1[2] &&
                rec1[1] < rec2[3] && rec2[1] < rec1[3];
    }
};