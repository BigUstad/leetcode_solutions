class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num_sum = 0;
        int max = nums.size();
        for(int& n: nums) {
            if (n > max) {
                max = n;
            }
            num_sum += n;
        }
        int sum_by_formula = (max * (max + 1)) / 2;
        return (sum_by_formula - num_sum);
    }
};
