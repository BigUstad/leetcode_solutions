#include <map>
class Solution {
public:
    // Find index i such that nums[i] <= target & nums[i+1] > target
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> lEleMap;
        vector<int> lRet;
        for (int i = 0; i <= nums.size() -1 ; i++)
        {
            lEleMap[nums.at(i)] = i;
        }
        for (int i = 0; i <= nums.size() -1 ; i++)
        {
            auto indexItr = lEleMap.find(target - nums.at(i));
            if (indexItr != lEleMap.end() && indexItr->second != i)
            {
                lRet.push_back(i);
                lRet.push_back(indexItr->second);
                break;
            }
        }
        
        return lRet;
    }
};
