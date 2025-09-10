class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> nums2_map; // element to index
        std::vector<int> nums_greater(nums2.size());
        // Monotonic stack will have indices of "lesser" elements
        // nums_greater will have the greater elements
        std::stack<int> m_stack;
        std::fill(nums_greater.begin(), nums_greater.end(), -1);
        int index = 0;
        // std::cout << "nums2 as-is : ";
        for (auto& n: nums2) {
            // std::cout << "  " << n;
            nums2_map[n] = index;
            // Monotonic stack should also be constructed here.
            // Indices?
            while (!m_stack.empty() && nums2[index] > nums2[m_stack.top()]) {
                nums_greater[m_stack.top()] = nums2[index];
                m_stack.pop();
            }
            m_stack.push(index);
            ++index;
        }
        /* std::cout << endl;
        std::cout << "nums2 ge: ";
        for (auto& r: nums_greater) {
            std::cout << "  " << r;
        }
        std::cout << endl; */
        index = 0;
        for (auto& n: nums1) {
            nums1[index++] = nums_greater[nums2_map[n]];
        }

        return nums1;
    }
};
