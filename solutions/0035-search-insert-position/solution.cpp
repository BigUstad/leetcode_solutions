class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low, high, mid;
        low = 0; high = nums.size() - 1;
        if ( nums.size() == 0 )
            return 0;
        if ( target < nums[0] )
            return 0;
        if ( target > nums[nums.size() - 1])
            return nums.size();
        while (low <= high )
        {
            mid = (high + low)/2;
            if ( nums[mid] > target )
                high = mid - 1;
            else if ( nums[mid] < target )
                low = mid + 1;
            else if ( nums[mid] == target )
                return mid;
        }
        return low;
    }
};
