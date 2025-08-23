class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        std::map<int,
                std::priority_queue<int>> sm;
        std::vector<std::vector<int>> l_ret;
        for (auto& v_s: items) {
            auto itr = sm.find(v_s[0]);
            if (itr == sm.end()) {
                std::priority_queue<int> pq;
                pq.push(v_s[1]);
                sm[v_s[0]] = pq;
                continue;
            }
            std::priority_queue<int>& pq = itr->second;
            pq.push(v_s[1]);
        }
        for (auto& s_p: sm) {
            int top_5_total = 0, n = 5;
            std::priority_queue<int>& pq = s_p.second;
            while(n-- && !pq.empty()) {
                top_5_total += pq.top();
                pq.pop();
            }
            std::vector<int> v_avg;
            // First element: id
            v_avg.push_back(s_p.first);
            // Second element: top 5 avg
            v_avg.push_back((top_5_total / 5));
            l_ret.push_back(v_avg);
        }
        return l_ret;
    }
};
