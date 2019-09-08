class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR all numbers. The one that stands out, shows itself.
        int finalXor = 0;
        for ( int i =0; i < nums.size(); ++i )
        {
            finalXor ^= nums.at(i);
        }
        return finalXor;
    }
};
