class MyQueue {
    stack<int, vector<int>> in;
    stack<int, vector<int>> out;

    void prepareOut() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
public:

    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if (empty()) {
            throw logic_error("pop from empty queue");
        }
        prepareOut();
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        if (empty()) {
            throw logic_error("pop from empty queue");
        }
        prepareOut();
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};