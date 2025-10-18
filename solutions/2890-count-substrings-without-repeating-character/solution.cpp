class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int s_start = 0;
        int count = 0, s_len(s.length());
        unordered_map<char, int> um;
        for(int s_end{}; s_end < s_len; ++s_end) {
            auto u_itr = um.find(s[s_end]);
            // If the character exists in the substring, we update the start pointer so that the substring has unique characters
            if (u_itr != um.end() && u_itr->second >= s_start) {
                s_start = u_itr->second + 1;
            }
            um[s[s_end]] = s_end;
            // Add the incremental number of new substrings formed after adding the current character. 
            count += (s_end - s_start + 1);
        }
        return count;
    }
};

