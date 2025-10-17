class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int s_start = 0, s_end = (k - 1);
        int s = nums.size(), l = (s - 1);
        unordered_map<int, int> nm;
        std::vector<int> v_ret;
        int i = 0;
        for (; i <= s_end; ++i) {
            nm[nums[i]]++;
        }
        while (s_end < l) {
            v_ret.push_back(nm.size());
            ++s_end;
            nm[nums[s_end]]++;
            auto start_itr = nm.find(nums[s_start]);
            start_itr->second--;
            if (!start_itr->second) {
                nm.erase(start_itr);
            }
            ++s_start;
        }
        // Last
        v_ret.push_back(nm.size());

        return v_ret;
    }
};
