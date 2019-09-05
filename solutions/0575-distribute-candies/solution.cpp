class Solution {
public:
    
    int distributeCandies(vector<int>& candies) {
        std::set<int, std::greater<int>> candySet;
        for ( int i=0; i < candies.size(); ++i )
        {
            candySet.insert(candies[i]);
        }
        float half = ceil((float)(candies.size())/2);
        int halfCandy = (int)half;
        int candySetSize = (int) (candySet.size());
        return std::min(candySetSize , halfCandy );
    }
};
