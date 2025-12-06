class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> sw;
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
            sw.erase(nums[i - k - 1]);
            auto itr = sw.find(nums[i]);
            if (itr != sw.end()) return true;
            sw.insert(nums[i]);
        }
        return false;
    }
};
