class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) { 
            return 0;
        }
        if (stones.size() == 1) {
            return stones[0];
        }
        if (stones.size() ==  2) {
            return std::abs(stones[1] - stones[0]);
        }
        std::priority_queue<int> pq;
        for (auto& s: stones) {
            pq.push(s);
        }
        
        while (!pq.empty()) {
            int t1 = pq.top(); pq.pop();
            if (pq.empty()) {
                return t1;
            }
            int t2 = pq.top(); pq.pop();
            if (t1 != t2) {
                int t = std::abs(t2 - t1);
                // std::cout << t << std::endl;
                pq.push(t);
            }
        }
        return 0;
    }
};
