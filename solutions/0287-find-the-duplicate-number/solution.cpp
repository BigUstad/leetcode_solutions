class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 2) {
            return nums[0];
        }
        std::unordered_set<int> num_set;
        // long num_sum = 0, range_sum = 0;
        // int min = INT_MAX, max = INT_MIN;
        for (int& n: nums) {
            // if (n > max) max = n;
            // if (n < min) min = n;
            auto p = num_set.insert(n);
            if (!p.second) {
                // Because it was already there?
                return n;
            }
            // num_sum += n;
        }
        /* if (min == max) {
            return min;
        } */
        /* for (const int& n: num_set) {
            range_sum += n;
        } */
        // std::cout << num_sum << ", " << range_sum << ", " << xor_result << std::endl;

        // return ((num_sum - range_sum) / (nums.size() - num_set.size()));
        return INT_MIN;
    }
};
