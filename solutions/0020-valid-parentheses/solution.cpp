class Solution {
public:
    bool isValid(string str) {
        // Input sanity checks.
        if(str.length() == 0)
        {
            return true;
        }
        if((str.length() % 2) != 0)
        {
            return false;
        }
        // Sanity check, if the input string contains any other char than the below six.
        // Return false.
        stack<char> cmp;
        char open_param = '(';
        char open_brack = '{';
        char open_sq = '[';
        char close_param = ')';
        char close_brack = '}';
        char close_sq = ']';
        for (size_t i=0; i < str.length(); i++)
        {
            if (str.at(i) == open_param ||
                str.at(i) == open_brack ||
                str.at(i) == open_sq)
            {
                cmp.push(str.at(i));
            }
            if (str.at(i) == close_param ||
                str.at(i) == close_brack ||
                str.at(i) == close_sq)
            {
                if (cmp.empty())
                    return false;
                char topOfStack = cmp.top();
                if (topOfStack == open_param && str.at(i) != close_param)
                {
                    return false;
                }
                if (topOfStack == open_sq && str.at(i) != close_sq)
                {
                    return false;
                }
                if (topOfStack == open_brack && str.at(i) != close_brack)
                {
                    return false;
                }
                cmp.pop();
            }
        }
        if (!cmp.empty())
            return false;
        return true;        
    }
};
