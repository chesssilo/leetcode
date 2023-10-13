class MinStack {
public:
    void push(int val) {
        if (st.empty()) {
            st.push(Item{val, val});
        } else {
            st.push(Item{val, min(val, st.top().min)});
        }
    }
    
    void pop() {
        if (st.empty()) {
            throw logic_error("pop from empty stack");
        }
        st.pop();
    }
    
    int top() const {
        if (st.empty()) {
            throw logic_error("top when empty stack");
        }
        return st.top().val;
    }
    
    int getMin() const {
        if (st.empty()) {
            throw logic_error("getMin when empty stack");
        }
        return st.top().min;        
    }
private:
    struct Item {
        int val;
        int min;
    };

    stack<Item, list<Item>> st;    
};