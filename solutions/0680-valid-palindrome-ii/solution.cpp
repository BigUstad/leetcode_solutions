class Solution {
public:
    bool checkPalindrome(string& s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) {
                break;
            }
            ++i; --j;
        }
        return (i >= j);
    }
    bool validPalindrome(string s) {
        std::size_t i = 0;
        std::size_t j = s.length() - 1;
        // Find the inflection point which is the 'haddi'
        std::size_t x = -1;
        if (s.length() == 0) {
            return false;
        }
        if (s.length() == 1) {
            return true;
        }
        if (s.length() == 2) {
            return (s[0] != s[1]);
        }
        while (i <= j) {
            if (s[i] != s[j]) {
                x = i;
                break;
            }
            ++i; --j;
        }
        return checkPalindrome(s, i, j - 1) || checkPalindrome(s, i + 1, j);
    }
};
