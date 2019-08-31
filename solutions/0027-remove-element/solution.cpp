class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int runner=0;
        int follower=0;
        if ( nums.size() == 0 )
            return nums.size();
        int reducer = 0;
        
        while (runner < nums.size() &&
                follower < nums.size() )
        {
            while (runner != nums.size() && nums[runner] == val )
            {
                reducer++;
                runner++;
            }
            if ( follower < nums.size() &&
                    runner < nums.size())
            {
                nums[follower] = nums[runner];
            }
            follower++;
            runner++;
        }
        return (reducer == 0)?nums.size():(nums.size() - reducer);
    }
};
