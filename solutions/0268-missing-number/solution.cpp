class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if ( nums.size() == 0 )
            return 0;
        int sumArray = 0;
        int numSum = (nums.size() * (nums.size() + 1))/2;
        for ( int i=0; i < nums.size(); ++i )
        {
            sumArray += nums[i];
        }
        return (numSum - sumArray);
    }
};
