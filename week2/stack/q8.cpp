int evaluatePostfix(const std::string& expr) {
    std::stack<int> st;  
    std::string num;      
    for (size_t i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ') {
            continue;
        }

        if (isdigit(expr[i])) {
            num.clear();
            while (i < expr.length() && isdigit(expr[i])) {
                num += expr[i];
                i++;
            }
            st.push(stoi(num)); 
            i--;  
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            int a = st.top(); 
            st.pop();
            int b = st.top(); 
            st.pop();
            
            switch (expr[i]) {
                case '+':
                    st.push(b + a);  
                    break;
                case '-':
                    st.push(b - a); 
                    break;
                case '*':
                    st.push(b * a);
                    break;
                case '/':
                    st.push(b / a);
                    break;
            }
        }
    }

    return st.top();
}
