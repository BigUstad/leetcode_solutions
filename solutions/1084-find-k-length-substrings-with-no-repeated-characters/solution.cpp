class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (k > 26) return 0;
        int s_start = 0, s_end = (k - 1);
        int len = s.length(), l = (s.length() - 1);
        int i = 0, count = 0;
        unordered_map<char, int> um;
        for (; i <= s_end; ++i) {
            um[s[i]]++;
        }
        while(s_end < len) {
            if (um.size() == k) {
                ++count;
            }
            if (s_end > l) {
                break;
            }
            auto u_itr = um.find(s[s_start]);
            u_itr->second--;
            if (!u_itr->second) {
                um.erase(u_itr);
            }
            ++s_start;
            ++s_end;
            um[s[s_end]]++;
        }
        return count;
    }
};
