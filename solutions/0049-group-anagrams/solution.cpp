class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<vector<std::string>> l_ret;
        std::map<std::string, vector<int>> am;
        int i = 0;
        for (auto s: strs) {
            std::sort(s.begin(), s.end());
            auto am_itr = am.find(s);
            if (am_itr != am.end()) {
                am_itr->second.push_back(i);
            } else {
                am[s] = {i};
            }
            ++i;
        }
        for (auto& pair: am) {
            i = 0;
            std::vector<std::string> vs(pair.second.size());
            for (auto& v_index: pair.second) {
                vs[i++] = strs.at(v_index);
            }
            l_ret.push_back(vs);
        }
        return l_ret;
    }
};
