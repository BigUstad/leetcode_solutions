class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Find first 0.
        size_t i = 0, s = nums.size();
        for (; i < s; ++i) {
            if (nums[i] == 0) {
                break;
            }
        }
        if (i == s) {
            return 0;
        }
        // Sliding window size = 3
        const size_t sl = 3;
        int count = 0;
        for (; i <= (s - 3); ++i) {
            if (nums[i]) {
                continue;
            }
            // std::cout << i << ". " << nums[i] << ", " << nums[i+1] << ", " << nums[i+2] << std::endl;
            flip(nums[i]);
            flip(nums[i + 1]);
            flip(nums[i + 2]);
            // std::cout << "F) " << i << ". " << nums[i] << ", " << nums[i+1] << ", " << nums[i+2] << std::endl;
            if (nums[i] == 0) {
                return -1;
            }
            ++count;
        }
        // Check final window
        if ((i < s && !nums[i]) ||
            ((i + 1) < s && !nums[i+1]) ||
            ((i + 2) < s && !nums[i+2])) {
            return -1;
        }
        return count;
    }
private:
    inline void flip(int &i) {
        if (i == 0) {
            i = 1;
            return;
        }
        i = 0;
    }
};
