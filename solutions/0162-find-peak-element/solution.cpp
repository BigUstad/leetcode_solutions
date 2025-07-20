class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        if (nums.size() == 2) {
            return ((nums[0] > nums[1])? 0 : 1);
        }
        size_t l = 0;
        size_t r = (nums.size() - 1);
        size_t m;
        while (l < r) {
            m = l + ((r - l) / 2);
            // std::cout << "M: " << m << std::endl;
            if (m > 0 && m < (nums.size() - 1) &&
                nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
                // Found the inflection point
                return m;
            } else if (m == 0 || m == (nums.size() - 1)) {
                // We've reached the end of search?
                if (m == 0) {
                    return (nums[m] < nums[m + 1])? (m + 1) : m;
                }
                return (nums[m] < nums[m - 1])? (m - 1) : m;
            }
            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else if (nums[m] >= nums[m + 1]) {
                // THis seems to be the important one that I missed.
                r = m;
            }
        }
        std::cout << "m: " << m << std::endl;
        if (l == r) {
            return l;
        }
        return -1;
    }
};
