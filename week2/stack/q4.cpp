#include <sstream>
std::string removeDuplicates(std::string S) {
    std::stack<char> st;

    for (size_t i = 0; i < S.length(); i++) {
        if (!st.empty() && st.top() == S[i]) {
            st.pop(); 
        } else {
            st.push(S[i]); 
        }
    }

    std::stringstream ss;
    while (!st.empty()) {
        ss << st.top() ;
        st.pop();
    }
    string str = ss.str();
    for(size_t i = 0; i < str.size(); i++)
        st.push(str[i]);
        
    ss.str(""); 
    ss.clear();
    while (!st.empty()) {
        ss << st.top() ;
        st.pop();
    }

    return ss.str();
}