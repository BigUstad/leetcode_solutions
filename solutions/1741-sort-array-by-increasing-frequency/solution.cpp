class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return nums;
        }
        std::unordered_map<int, int> nm; // nums map
        for (auto& n: nums) {
            nm[n]++;
        }
        auto comp = [&nm] (const int& p1, const int& p2) {
            return (nm[p1] > nm[p2] ||
                    (nm[p1] == nm[p2] && p1 < p2));
        };
        std::priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        std::vector<int> v_ret;
        for (auto n_itr: nm) {
            pq.push(n_itr.first);
        }
        while (!pq.empty()) {
            const int& n = pq.top();
            auto n_itr = nm.find(n);
            int& cnt = n_itr->second;
            while (cnt--) {
                v_ret.push_back(n);
            }
            pq.pop();
        }
        return v_ret;
    }
};
