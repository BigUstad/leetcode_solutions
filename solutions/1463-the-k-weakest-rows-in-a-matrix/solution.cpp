class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        std::vector<int> v_ret;
        auto comp = [] (const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            return (p1.first > p2.first ||
            (p1.first == p2.first && p1.second > p2.second));
        };
        std::priority_queue<std::pair<int, int>,
                std::vector<std::pair<int, int>>,
                decltype(comp)> pq;
        for (int i = 0; i < mat.size(); ++i) {
            int count_1s = 0;
            for (auto& v_i: mat[i]) {
                if (v_i == 1) {
                    ++count_1s;
                }
            }
            pq.push({count_1s, i});
        }
        while (k--) {
            auto p = pq.top();
            v_ret.push_back(p.second);
            pq.pop();
        }
        return v_ret;
    }
};
