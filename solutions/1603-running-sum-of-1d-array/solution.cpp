class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int index = 1; index < nums.size(); ++index) {
            nums[index] = (nums[index - 1] + nums[index]);
        }
        return nums;
    }
};
