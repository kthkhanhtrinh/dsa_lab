bool isValidParentheses (string s){
    /*TODO*/
    stack<char> st;
    // for(size_t i = 0; i < s.length(); i++)
    for(char c : s)
    {
        if(c == '(' || c == '{' || c == '[')
            st.push(c);
            

        if(c == ')')
        {
            if(!st.empty() && st.top() == '(')
                st.pop();
            else return false;
        }
        if(c == ']')
        {
            if(!st.empty() && st.top() == '[')
                st.pop();
            else return false;
        }
        if(c == '}')
        {
            if(!st.empty() && st.top() == '{')
                st.pop();
            else return false;
        }

        

    }
    return st.empty();
}