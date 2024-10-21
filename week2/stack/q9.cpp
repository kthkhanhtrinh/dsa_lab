class QueueS {
private:
    stack<int> st;

public:
    void enqueue(int value) {
        st.push(value);
    }
    
    int dequeue() {
        if(st.empty())
            throw out_of_range("Empty queue");
        stack<int> tmp;
        while(!st.empty())
        {
            tmp.push(st.top());
            st.pop();
        }
        int result = tmp.top();
        tmp.pop();
        while(!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
        return result;
    }
    
    int front() {
        if(st.empty())
            throw out_of_range("Empty queue");
            
        if(st.empty())
            throw out_of_range("Empty queue");
        stack<int> tmp;
        while(!st.empty())
        {
            tmp.push(st.top());
            st.pop();
        }
        int result = tmp.top();
        // tmp.pop();
        while(!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
        return result;
    }
    
    int rear() {
        if(st.empty())
            throw out_of_range("Empty queue");
        return st.top();
    }
    
    string toString() {
        // cout << "FRONT| ";
        stack<int> tmp;
        stringstream res;
        res << "FRONT|";
        while(!st.empty())
        {
            tmp.push(st.top());
            st.pop();
        }
        while(!tmp.empty())
        {
            res << " " << tmp.top();
            st.push(tmp.top());
            tmp.pop();
        }
        res <<"|REAR";
        return res.str();
    }
};