int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER --> sliding window, use deque
    int n = nums.size();
    if (k > n || k <= 0) return 0;
    deque<int> dq;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        
        dq.push_back(i);

        if (i >= k - 1) {
            sum += nums[dq.front()];  
        }
    }
    return sum;
}