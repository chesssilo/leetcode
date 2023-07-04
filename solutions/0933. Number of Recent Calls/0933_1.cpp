// Time complexity: O(1)
// Space complexity: O(1)
class RecentCounter {
    queue<int> q;   
public:
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }    
};