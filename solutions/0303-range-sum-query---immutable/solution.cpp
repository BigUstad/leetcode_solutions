class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        if (nums.size() == 1) {
            prefix_sum.push_back(nums[0]);
            return;
        }
        prefix_sum.push_back(nums[0]);
        for (int index = 1; index < nums.size(); ++index) {
            prefix_sum.push_back((prefix_sum.back() + nums[index]));
        }
    }
    
    int sumRange(int left, int right) {
        if (!left) {
            return prefix_sum[right];
        }
        return (prefix_sum[right] - prefix_sum[left - 1]);
    }
private:
    std::vector<int> prefix_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
