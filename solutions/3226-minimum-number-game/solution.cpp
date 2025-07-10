class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        std::vector<int> v_ret;
        for (auto& n: nums) {
            pq.push(n);
        }
        while (!pq.empty()) {
            int alice_pick = pq.top(); pq.pop();
            int bob_pick = pq.top(); pq.pop();
            v_ret.push_back(bob_pick);
            v_ret.push_back(alice_pick);
        }
        return v_ret;
    }
};
