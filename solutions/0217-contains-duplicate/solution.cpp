class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> numsSet;
        std::set<int>::iterator sItr;
        for ( int i = 0; i < nums.size() ; ++i)
        {
            sItr = numsSet.find(nums[i]);
            if ( sItr != numsSet.end() )
            {
                // Found it.
                return true;
            }
            else
            {
                numsSet.insert(nums[i]);
            }
        }
        return false;
    }
};
