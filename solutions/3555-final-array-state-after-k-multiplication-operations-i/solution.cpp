class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int min = INT_MAX;
        for(auto&n : nums) {
            pq.push(n);
        }
        int i = 0;
        while(k--) {
            min = pq.top(); pq.pop();
            for(auto&n : nums) {
                if (n == min) {
                    n = (n * multiplier);
                    pq.push(n);
                    break;
                }
            }
        }
        return nums;
    }
};
