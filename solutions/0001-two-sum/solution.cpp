class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> store;
        int index = 0;
        for(int i: nums) {
            store[i] = index++;
        }
        index = 0;
        for(int i: nums) {
            int diffI = target - i;
            auto fItr = store.find(diffI);
            if (fItr != store.end() && index != fItr->second) {
                result.push_back(std::min(fItr->second,index));
                result.push_back(std::max(fItr->second,index));
                break;
            }
            index++;
        }
        return result;
    }
};
