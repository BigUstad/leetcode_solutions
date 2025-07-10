class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::priority_queue<int> pq;
        for (auto& n: nums) {
            pq.push(n);
        }
        int i = pq.top(); pq.pop();
        int j = pq.top(); pq.pop();
        
        return ((i - 1) * (j - 1));
    }
};
