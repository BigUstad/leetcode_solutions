class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> nm;
        std::vector<int> v_ret;
        for (auto& n: nums1) {
            nm[n]++;
        }
        for (auto& n: nums2) {
            if (nm[n]) {
                v_ret.push_back(n);
                nm[n]--;
            }
        }
        return v_ret;
    }
};
