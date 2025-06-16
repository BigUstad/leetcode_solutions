class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0 || s.length() == 1) {
            return true;
        }
        if (s.length() == 2) {
            if (!std::isalnum(s[0]) || !std::isalnum(s[1])) {
                return true;
            }
            return std::tolower(s[0]) == std::tolower(s[1]);
        }
        std::size_t i = 0;
        std::size_t j = s.length() - 1;
        while (i <= j) {
            if (!std::isalnum(s[i])) {
                ++i;
                continue;
            }
            if (!std::isalnum(s[j])) {
                --j;
                continue;
            }
            if (i != j && std::tolower(s[i]) != std::tolower(s[j])) {
                break;
            }
            ++i; --j;
        }
        return (i >= j);
    }
};
