class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) {
            return nums;
        }
        std::vector<int> l_ret;
        std::unordered_map<int, int> m;
        // using lambda function for comparator.
        // second element is count
        auto comparator = [&m](int i, int j) {
            return m[i] > m[j];
        };
        std::priority_queue<int, std::vector<int>, decltype(comparator)> pq(comparator);
        for (auto& n: nums) {
            m[n] += 1;
        }
        for (auto& pair: m) {
            pq.push(pair.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while(!pq.empty()) {
            l_ret.push_back(pq.top());
            pq.pop();
        }
        return l_ret;
    }
};
