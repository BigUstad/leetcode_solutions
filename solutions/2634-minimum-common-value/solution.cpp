class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (auto& n: nums2) {
            if (std::binary_search(nums1.begin(), nums1.end(), n)) {
                return n;
            }
        }

        return -1;
    }
};

