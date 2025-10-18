class Solution {
public:
    int countGoodSubstrings(string s) {
        // Sliding window size of 3
        int s_start = 0, s_end = 2, count = 0;
        int len = s.length(), last = (len - 1);
        unordered_map<char, int> um;
        for (int i = 0; i < 3; ++i) {
            um[s[i]]++;
        }
        while (s_end < last) {
            if (um.size() == 3) {
                ++count;
            }
            auto u_itr = um.find(s[s_start]);
            if (u_itr->second == 1) {
                um.erase(u_itr);
            } else {
                u_itr->second--;
            }
            ++s_start; ++s_end;
            um[s[s_end]]++;
        }
        // Final count
        if (um.size() == 3) ++count;
        return count;
    }
};
