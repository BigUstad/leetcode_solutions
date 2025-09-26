class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        std::vector<int> v_ret;
        std::sort(nums.begin(), nums.end());
        std::vector<int> nums_prefix_sum;
        for (int index = 0; index < nums.size(); ++index) {
            if (index == 0) {
                nums_prefix_sum.push_back(nums[index]);
                continue;
            }
            nums_prefix_sum.push_back(nums_prefix_sum[index - 1] + nums[index]);
        }
        /* std::cout << "nums_prefix_sum: ";
        for (auto& n: nums_prefix_sum) {
            std::cout << "  " << n;
        }
        std::cout << std::endl; */
        // std::cout << "Prefix sum ele:  ";
        int len = nums_prefix_sum.size();
        for (auto& q: queries) {
            auto q_itr = std::lower_bound(nums_prefix_sum.begin(), nums_prefix_sum.end(), q);
            if (q_itr != nums_prefix_sum.end()) {
                // std::cout << "[" << q << "," << *q_itr << "]. ";
                int dist = std::distance(nums_prefix_sum.begin(), q_itr);
                if (*q_itr <= q) {
                    ++dist;
                }
                v_ret.push_back(dist);
            } else {
                // std::cout << "[" << q << ",NA" << "]. ";
                v_ret.push_back(len);
            }
            int q_index = q_itr - nums_prefix_sum.begin();
            
        }
        // std::cout << std::endl;
        return v_ret;
    }
};
