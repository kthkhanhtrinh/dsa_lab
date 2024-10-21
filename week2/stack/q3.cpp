// iostream, stack and vector are included
// có 1 stack duy trì mảng đang tăng hoặc đang giảm
vector<int> nextGreater(vector<int>& arr){
    //travel from the back
    // push item, if item smaller than top -> push, else pop and push a new one
    
    stack<int> st;
    int size = arr.size();
    for(int i = size - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= arr[i])
            st.pop();
            
        int next_greater = st.empty() ? -1 : st.top();
        st.push(arr[i]);
        arr[i] = next_greater;
    }
    return arr;
}