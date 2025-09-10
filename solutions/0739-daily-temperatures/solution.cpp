class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> v_warmer(temperatures.size());
        std::stack<int> m_stack;
        // std::fill(v_warmer.begin(), v_warmer.end(), 0);
        int index = 0;
        for (auto& t: temperatures) {
            while (!m_stack.empty() && temperatures[index] > temperatures[m_stack.top()]) {
                v_warmer[m_stack.top()] = (index - m_stack.top());
                m_stack.pop();
            }
            m_stack.push(index++);
        }
        /* std::cout << "warmer day wait: ";
        for(auto& w: v_warmer) {
            std::cout << "  " << w;
        }
        std::cout << std::endl; */
        return v_warmer;
    }
};
