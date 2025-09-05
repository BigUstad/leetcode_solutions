class Solution {
public:
    void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, int start, std::vector<int> current) {
        result.push_back(current);
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(nums, result, i + 1, current);
            current.pop_back(); // We're done with i and we are going to the next one.
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // Sort helps only choosing "numbers greater than" x
        // std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> l_ret;
        if (nums.empty()) {
            return l_ret;
        }
        if (nums.size() == 1) {
            std::vector<int> single;
            l_ret.push_back(single);
            single.push_back(nums[0]);
            l_ret.push_back(single);
            return l_ret;
        }

        backtrack(nums, l_ret, 0 , {});
        return l_ret;
    }
};
