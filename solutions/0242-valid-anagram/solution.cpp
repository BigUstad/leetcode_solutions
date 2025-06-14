class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        std::vector<short> v(26, 0);
        for (auto c: s) {
            v[c - 'a']++;
        }
        for (auto c: t) {
            v[c - 'a']--;
        }
        for (auto i: v) {
            if (i > 0) {
                return false;
            }
        }
        return true;
    }
};
