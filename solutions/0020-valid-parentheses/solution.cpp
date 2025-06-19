class Solution {
public:
    bool isValid(string str) {
        // Input sanity checks.
        if(str.length() == 0) {
            return true;
        }
        if((str.length() % 2) != 0) {
            return false;
        }
        // Sanity check, if the input string contains any other char than the below six.
        // Return false.
        std::stack<char> cmp;
        char open_param = '('; char close_param = ')';
        char open_brack = '{'; char close_brack = '}';
        char open_sq = '['; char close_sq = ']';
        for (size_t i=0; i < str.length(); i++)
        {
            if (str.at(i) == open_param ||
                str.at(i) == open_brack ||
                str.at(i) == open_sq)
            {
                cmp.push(str.at(i));
                continue;
            }
            if (cmp.empty()) {
                return false;
            }
            char top = cmp.top();
            bool check_param_fail =  (top == open_param && str.at(i) != close_param) ||
                                (top == open_sq && str.at(i) != close_sq) ||
                                (top == open_brack && str.at(i) != close_brack);
            if (check_param_fail) {
                return false;
            }
            cmp.pop();
        }
        if (!cmp.empty())
            return false;
        return true;        
    }
};

