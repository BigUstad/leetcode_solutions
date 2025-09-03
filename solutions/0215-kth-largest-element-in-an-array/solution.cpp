class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> pq;
        int l_ret = INT_MIN;
        if (nums.size() < k) {
            return l_ret;
        }
        for (auto& n: nums) {
            pq.push(n);
        }
        while (k--) {
            l_ret = pq.top(); pq.pop();
        }
        return l_ret;
    }
};
