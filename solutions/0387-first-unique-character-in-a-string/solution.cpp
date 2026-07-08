class Solution {
public:
    int firstUniqChar(string s) {
        // std::unordered_map<char, int> repeats_table;
        std::array<int, 26> char_table;
        for (auto& c: s) {
            // repeats_table[c]++;
            char_table[c]++;
        }
        int i = 0;
        for (auto&c: s) {
            // if (repeats_table[c] == 1) {
            if (char_table[c] == 1) {
                return i;
            }
            ++i;
        }
        return -1;
    }
};
