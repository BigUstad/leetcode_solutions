class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if ( nums.size() == 0 || nums.size() == 1 )
        {
            return nums.size();
        }
        int runner = 1;
        int follower = 0;
        for(; runner < nums.size();
                ++runner )
        {
			if ( nums[runner] != nums[follower] )
            {
                follower++;
                nums[follower] = nums[runner];
            }
        }
        // std::cout << "Delete " << follower << " till end:" << nums.size()-1 << std::endl;
        vector<int>::iterator followEle = nums.begin() + follower;
        vector<int>::iterator end = nums.end();
        //nums.erase(followEle, end);
        //nums.erase(followEle);
        return follower+1;
    }
};
