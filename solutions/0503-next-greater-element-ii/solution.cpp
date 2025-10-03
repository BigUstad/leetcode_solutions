class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return {};
        if (nums.size() == 1) return {-1};
        std::vector<int> result(nums.size(), -1);
        std:stack<int> m_stack;
        int i = 0;
        for (; i < nums.size(); ++i) {
            while (!m_stack.empty() && nums[i] > nums[m_stack.top()]) {
                result[m_stack.top()] = nums[i];
                m_stack.pop();
            }
            m_stack.push(i);
        }
        // We've have reached the end of the array
        i = 0;
        while (!m_stack.empty()) {
            if (i >= (nums.size() - 1)) {
                break;
            }
            while (i < m_stack.top() && nums[i] <= nums[m_stack.top()]) {
                ++i;
            }
            if (i < m_stack.top()) {
                result[m_stack.top()] = nums[i];
            }
            m_stack.pop();
        }
        return result;
    }
};
