const int ZERO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

template<typename T, size_t SIZE = 16>
class BigList {
    struct Leaf {
        T a[SIZE];
        Leaf* next;
        int filled;
    };

    Leaf* top;
public:

    typedef T value_type;
    typedef T& reference;
    typedef T& const_reference;
    typedef size_t size_type;

    BigList()
        : top(nullptr)
    {}  

    void push_back(const T& value) {
        if (top == nullptr || top->filled == SIZE) {
            Leaf* newTop = new Leaf();
            newTop->next = top;
            newTop->filled = 0;
            top = newTop;
        }
        top->a[top->filled] = value;
        top->filled++;
    }  

    void pop_back() {
        assert(top != nullptr);
        assert(top->filled != 0);
        top->filled--;
        if (top->filled == 0) {
            Leaf* oldTop = top;
            top = oldTop->next;
            delete oldTop;
        }
    }

    const T& back() const {
        assert(top != nullptr);
        assert(top->filled != 0);
        return top->a[top->filled - 1];
    }

    T& back() {
        assert(top != nullptr);
        assert(top->filled != 0);
        return top->a[top->filled - 1];
    }

    bool empty() const {
        return top == nullptr;
    }
};

class MinStack {
    struct Item {
        int val;
        int min;
    };

    stack<Item, BigList<Item>> st;    
public:
    void push(int val) {
        if (st.empty()) {
            st.push(Item{val, val});
        } else {
            st.push(Item{val, std::min(val, st.top().min)});
        }
    }
    
    void pop() {
        if (st.empty()) {
            throw std::logic_error("pop from empty stack");
        }
        st.pop();
    }
    
    int top() {
        if (st.empty()) {
            throw std::logic_error("top when empty stack");
        }
        return st.top().val;
    }
    
    int getMin() {
        if (st.empty()) {
            throw std::logic_error("getMin when empty stack");
        }
        return st.top().min;        
    }   
};