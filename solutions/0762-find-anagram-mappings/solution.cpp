class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<int> lRet;
        std::map<int, int> lNumMap;
        if ( nums1.size() != nums2.size() ) {
            return lRet;
        }
        for ( auto& n1: nums1 ) {
            lNumMap[n1] = -1;
        }
        int i = 0;
        for ( auto& n2: nums2 ) {
            auto itr = lNumMap.find(n2);
            if ( itr != lNumMap.end() ) {
                itr->second = i;
            }
            i++;
        }
        for ( auto& n1: nums1 ) {
            auto itr = lNumMap.find(n1);
            if ( itr != lNumMap.end() ) {
                lRet.push_back(itr->second);
            }
        }
        return lRet;
    }
};
