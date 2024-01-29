// Time complexity: Constructor: O(1), push(x): O(1), pop(): O(n), peek(): O(n), empty(): O(1)
// Space complexity: O(n)
class MyQueue {
public:
    void push(int x) {
        input.push(x);
    }

    int pop() {
        peek();
        const int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        if (output.empty())
            while (!input.empty())
                output.push(input.top(), input.pop());
        return output.top();        
    }

    bool empty() {
        return input.empty() && output.empty();
    }
private:
    stack<int> input;
    stack<int> output;    
};