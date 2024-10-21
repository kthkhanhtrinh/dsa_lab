// iostream, vector and queue are included
// You can write helper methods

long long nthNiceNumber(int n) {
    queue<string> q;
    q.push("2");
    q.push("5");
    
    string nice_num;
    
    for (int i = 0; i < n; i++) {
        nice_num = q.front();
        q.pop();
        
        q.push(nice_num + "2");
        q.push(nice_num + "5");
    }
    
    // Return the Nth nice number as a long long
    return stoll(nice_num); // Convert the string to long long
}