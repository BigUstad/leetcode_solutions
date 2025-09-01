class Solution {
public:
    bool binarySearch(vector<int>& nums_copy, int low, int high, int target) {
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            bool found_mid = (nums_copy[mid] == target);
            bool before_mid = (nums_copy[mid] > target);
            if (found_mid) {
                // std::cout << "Found mid? " << ((found_mid)?"Yes" : "No") << " for " << nums_copy[mid] << ", " << target << std::endl;
                return true;
            }
            if (before_mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> l_ret;
        auto three_sum_hasher = [] (const std::tuple<int, int, int>& t) {
            std::string s0 = std::to_string(std::get<0>(t));
            std::string s1 = std::to_string(std::get<1>(t));
            std::string s2 = std::to_string(std::get<2>(t));
            std::string s = s0 + "," + s1 + "," + s2;
            std::hash<std::string> s_hasher;
            std::size_t s_hash = s_hasher(s);
            return s_hash;
        };
        std::unordered_set<std::tuple<int, int, int>, decltype(three_sum_hasher)> l_result_set;
        std::vector<int> nums_copy(nums);
        std::sort(nums_copy.begin(), nums_copy.end());
        // I'm carving out a special case for all 0's
        if (nums_copy[0] == 0 && nums_copy.size() >=3 && nums_copy[(nums_copy.size() - 1)] == 0) {
            std::vector<int> ele = {0, 0, 0};
            return {ele};
        }
        if (nums_copy.size() >= 3 && nums_copy[0] == nums_copy[nums_copy.size() - 1]) {
            return {};
        }
        /* std::cout << "Sorted: [";
        for (auto& n: nums_copy) {
            std::cout << n << ", ";
        }
        std::cout << "]" << std::endl; */
        // Take a number at the end of the array.
        // There ought to be 2 numbers which equals the sum of two of the numbers.
        for (int i = (nums_copy.size() - 1); i >= 0; --i) {
            // std::cout << "Trying to find pair for: " << i << ") " << nums_copy[i] << std::endl;

            // binary search in order to find the second & third numbers
            for (int j = 0; j <= (i - 1); ++j) {
                int complement = 0 - nums_copy[i] - nums_copy[j];
                int upper_bound_index = (i - 1);
                // std::cout << i << ": " << nums_copy[i] << ", 2: " << nums_copy[j] << ", 3?: " << complement << std::endl;
                if (binarySearch(nums_copy, j + 1 ,upper_bound_index , complement)) {
                    l_result_set.insert(std::make_tuple(complement, nums_copy[j], nums_copy[i]));
                }
            }
        }
        if (l_result_set.size() > 0) {
            for (auto& r: l_result_set) {
                l_ret.push_back({std::get<0>(r), std::get<1>(r), std::get<2>(r)});
            }
        }
        return l_ret;
    }
};

