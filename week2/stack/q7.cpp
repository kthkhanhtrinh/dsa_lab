vector<int> stock_span(const vector<int>& ns) {
    // STUDENT ANSWER
    vector<int> output;
    int n = ns.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i - 1; j >= 0; j--)
            if (ns[j] < ns[i])
                count++;
            else break;
        output.push_back(count + 1);
        count = 0;
    }
    return output;
    
}
