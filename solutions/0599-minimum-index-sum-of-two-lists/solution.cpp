class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> lRet;
        std::map<std::string, std::pair<int,int>> interestMap;
        for (int i=0; i < list1.size(); ++i)
        {
            interestMap[list1.at(i)] = std::make_pair(i,-1);
        }
        for (int i=0; i < list2.size(); ++i)
        {
            auto lItr = interestMap.find(list2.at(i));
            if ( lItr != interestMap.end() )
            {
                // lRet.push_back(list2.at(i));
                lItr->second.second = i;
            }
        }
        int minCount = INT_MAX;
        for ( auto lItr = interestMap.begin(); lItr != interestMap.end();
                ++lItr)
        {
            if ( lItr->second.first != -1 && lItr->second.second != -1)
            {
                int sum = lItr->second.first + lItr->second.second;
                if (sum < minCount )
                {
                    lRet.clear();
                    minCount = sum;
                    lRet.push_back(lItr->first);
                }
                else if ( sum == minCount )
                {
                    lRet.push_back(lItr->first);
                }
            }
        }
        return lRet;
    }
};
