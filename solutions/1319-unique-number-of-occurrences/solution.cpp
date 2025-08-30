class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> am;
        std::unordered_set<int> vs;
        for (int& a: arr) {
            am[a]++;
        }
        for (auto& am_p: am) {
            vs.insert(am_p.second);
        }
        return (vs.size() == am.size());
    }
};
