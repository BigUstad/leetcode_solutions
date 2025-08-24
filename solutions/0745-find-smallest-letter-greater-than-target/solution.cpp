class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        std::array<bool, 26> all_chars;
        all_chars.fill(false);
        uint8_t s_target = target - 'a';
        // std::cout << "target: " << target << ". s_target: " << s_target << std::endl;
        for(char& c: letters) {
            uint8_t s_c = c - 'a';
            if ((s_c > s_target) &&
                 !all_chars[s_c]) {
                all_chars[s_c] = true;
            }
        }
        while (s_target < 26) {
            if (all_chars[s_target]) {
                return char('a' + s_target);
            }
            ++s_target;
        }
        return letters[0];
    }
};
