class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> lRetS;
        vector<int>& first((nums1.size() < nums2.size())?nums1:nums2);
        vector<int>& second((nums1.size() < nums2.size())?nums2:nums1);
        std::unordered_set<int> firstSet(first.begin(), first.end());
        for ( auto i: second )
        {
            if ( firstSet.find(i) != firstSet.end() )
            {
                lRetS.insert(i);
            }
        }
        vector<int> lRet(lRetS.begin(), lRetS.end());
        lRetS.clear();
        return lRet;
    }
};
