class Solution {
public:
    int balancedStringSplit(string s) {
        if ((s.length() % 2) > 0) {
            return 0;
        }
        // Two pointer approach
        // See L decrease by 1. First letter L start with -1.
        // See R increase by 1. First letter R start with 1.
        // When it becomes 0, Increment balanced_count.
        int balanced_count = 0;
        short l_r_count = SHRT_MIN;
        for (auto& c: s) { 
            if (c != 'L' && c != 'R') {
                continue;
            }
            if (c == 'L') {
                l_r_count = (l_r_count == SHRT_MIN)? -1 : (l_r_count - 1);
            }
            if (c == 'R') {
                l_r_count = (l_r_count == SHRT_MIN)? 1 : (l_r_count + 1);
            }
            if (l_r_count == 0) {
                ++balanced_count;
            }
        }
        return balanced_count;
    }
};
