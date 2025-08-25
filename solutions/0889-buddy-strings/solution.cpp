class Solution {
public:
    // all same characters in goal
    bool caseOne(string& s, string& goal) {
        // std::cout << "case one" << std::endl;
        if (goal.length() < 2)
            return false;
        unsigned short low = 0, high = (goal.size() - 1);
        while (low < high) {
            if (s[low] != s[high]) {
                break;
            }
            ++low;--high;
        }
        if (low >= high) {
            return true;
        }
        return false;
    }
    // goal and s are same & greater than length 2
    bool caseTwo(string& s, string& goal) {
        // std::cout << "case two" << std::endl;
        if (s != goal)
            return false;
        if (s == goal && s.length() <= 2) {
            return false;
        }
        // There has to be atleast one repeating char to swap
        if (s == goal) {
            std::array<char, 26> ac;
            ac.fill(0);
            for (auto&c : s) {
                ac[c - 'a']++;
            }
            for (auto& c: ac) {
                if (c > 1) {
                    return true;
                }
            }
        }
            
        return false;
    }
    // Finds 2 characters that are not equal, swaps them & checks equality
    // Won't work for cases less than 2 characters
    bool caseThree(string& s, string& goal) {
        // std::cout << "case three" << std::endl;
        if (s.length() < 2) {
            return false;
        }
        if (s.length() == 2) {
            std::swap(goal[0], goal[1]);
            return s == goal;
        }
        bool match_fail_once = false, match_fail_twice = false;
        short index_fail_once = -1, index_fail_twice = -1;

        for (unsigned short i = 0; i < goal.length(); ++i) {
            if (s[i] != goal[i]) {
                if (match_fail_once && match_fail_twice) {
                    return false;
                }
                if (!match_fail_once) {
                    match_fail_once = true;
                    index_fail_once = i;
                    continue;
                }
                if (!match_fail_twice) {
                    match_fail_twice = true;
                    index_fail_twice = i;
                }
            }
        }
        if (index_fail_once != -1 && index_fail_twice != -1) {
            std::swap(goal[index_fail_once], goal[index_fail_twice]);
            return s == goal;
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        return caseOne(s, goal) || caseTwo(s, goal) || caseThree(s,goal);
    }
};
