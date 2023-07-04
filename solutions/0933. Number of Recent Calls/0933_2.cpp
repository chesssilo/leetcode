// Time complexity: O(1)
// Space complexity: O(1)
template <typename T, size_t MAX_SIZE>
class MaxSizeQueue {
    T a[MAX_SIZE];
    size_t first;
    size_t after;
    size_t count;
public:
    MaxSizeQueue()
        : first(0)
        , after(0)
        , count(0)
    {}

    void push(const T &value) {
        assert(count < MAX_SIZE);
        a[after] = value;
        after++;
        if (after == MAX_SIZE) {
            after = 0;
        }
        count++;
    } 

    const T& front() const {
        assert(count > 0);
        return a[first];
    } 

    void pop() {
        assert(count > 0);
        first++;
        if (first == MAX_SIZE) {
            first = 0;
        }
        count--;
    } 

    size_t size() const {
        return count;
    } 
};

class RecentCounter {
    MaxSizeQueue<int, 3002> q;
public:
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }       
};