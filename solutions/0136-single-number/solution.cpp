class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = (INT_MAX / 2);
        for (int& n: nums) {
            result ^= n;
        }
        result ^= (INT_MAX / 2);
        // std::cout << result << std::endl;
        return result;
    }
};
