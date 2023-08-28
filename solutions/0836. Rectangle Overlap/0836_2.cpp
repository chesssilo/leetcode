// Time complexity: O(1)
// Space complexity: O(1)
struct Rect {
    const int minX;
    const int maxX;
    const int minY;
    const int maxY;

    Rect(const vector<int> &r) 
        : minX(r[0])
        , minY(r[1])
        , maxX(r[2])
        , maxY(r[3])
    {
        assert(minX <= maxX);
        assert(minY <= maxY);
    }    
};

class Solution {
    bool isRectangleOverlap(int min1, int max1, int min2, int max2) const {
        return !(min1 >= max2 || min2 >= max1);
    }

public:

    bool isRectangleOverlap(const Rect &r1, const Rect &r2) const {
        return isRectangleOverlap(r1.minX, r1.maxX, r2.minX, r2.maxX) && 
                isRectangleOverlap(r1.minY, r1.maxY, r2.minY, r2.maxY);
    }

    bool isRectangleOverlap(const vector<int> &r1, const vector<int> &r2) const {
        return isRectangleOverlap(Rect(r1), Rect(r2));
    }
};