void interleaveQueue(queue<int>& q){
    int n = q.size();
    if (n % 2 != 0) return; 

    queue<int> firstHalf;
    int halfSize = n / 2;

    for (int i = 0; i < halfSize; i++) {
        firstHalf.push(q.front());
        q.pop();
    }


    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}