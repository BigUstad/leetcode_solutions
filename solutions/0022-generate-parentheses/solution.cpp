class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // std::cout << __FUNCTION__ << "::" << __LINE__ << " cur: " << cur << std::endl;
        std::vector<std::string> result;
        int open_count = 0, close_count = 1;
        validParenthesisHelper("", 0, 0, n, result);
        return result;
    }
private:
    void validParenthesisHelper(std::string cur, int open_count, int close_count, int n, std::vector<std::string>& result) {
        if (cur.length() == (n * 2)) {
            result.push_back(cur);
            return;
        }
        if (open_count < n) {
            cur.append(1, '(');
            // std::cout << (open_count + 1) << ", " << close_count << ". " << cur << std::endl;
            validParenthesisHelper(cur, open_count + 1, close_count, n, result);
            cur.pop_back();
        }
        // 1 or more ')' can be added to 
        if (open_count > close_count) {
            cur.append(1, ')');
            // std::cout << open_count << ", " << (close_count + 1) << ". " << cur << std::endl;
            validParenthesisHelper(cur, open_count, close_count + 1, n, result);
            cur.pop_back();
        }
    }
};
