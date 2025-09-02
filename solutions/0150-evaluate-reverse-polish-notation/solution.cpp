class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int l_ret = -1;
        std::stack<int> num_stack;
        std::unordered_set<std::string> operators = {"+", "-", "*", "/"};
        for (std::string& t: tokens) {
            if (operators.find(t) == operators.end()) {
                // num
                num_stack.push(std::stoi(t));
            } else {
                int n2 = num_stack.top(); num_stack.pop();
                int n1 = num_stack.top(); num_stack.pop();
                // std::cout << "op: " << n1 << " " << t << " " << n2 << std::endl;
                if (t == "+") {
                    l_ret = n1 + n2;
                } else if (t == "-") {
                    l_ret = n1 - n2;
                } else if (t == "*") {
                    l_ret = n1 * n2;
                } else if (t == "/") {
                    l_ret = n1 / n2;
                }
                num_stack.push(l_ret);
            }
        }
        // Result should be on top.
        return ((num_stack.empty()) ? -1 : num_stack.top());
    }
};
