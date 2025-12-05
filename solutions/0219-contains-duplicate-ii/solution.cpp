class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> sw;
        int i = 0;
        for (; i <= k && i < nums.size(); ++i) {
            auto p = sw.insert(nums[i]);
            if (!p.second) {
                return true;
            }
        }
        // Now use the sliding window to the rest of the array.
        // If there is a duplicate return true.
        for (; i && i < nums.size(); ++i) {
            // Find the previous vector element.
            // Remove the entry in sw. 0 unlikely to appear.
            auto itr = sw.find(nums[i - k - 1]);
            sw.erase(itr);
            auto p = sw.insert(nums[i]);
            if (!p.second) {
                return true;
            }
        }
        return false;
    }
};
