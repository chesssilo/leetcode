class Solution {
public:
    int minPartitions(string n) {
        int temp = '0';

        for (int i = 0; i < n.length(); i++) 
            if (n[i] > temp) temp = n[i];

        return temp - '0';
    }
};