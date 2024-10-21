int baseballScore(string ops){
/*TODO*/
    stack<int> st;
    
    for(size_t i = 0; i < ops.length(); i++)
    {
        if(ops[i] == 'C' && !st.empty())
            st.pop();
        
        if(ops[i] == 'D' && !st.empty())
        {
            int it = st.top();
            st.push(it*2);
        }
        
        if(ops[i] == '+')
        {
            int it1 = st.top();
            st.pop();
            int it2 = st.top();
            st.push(it1);
            st.push(it1 + it2);
        }
        
        if(ops[i] > 47 && ops[i] < 58)
        {
            st.push(int(ops[i]) - 48);
        }
    }
    
    int res = 0;
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}