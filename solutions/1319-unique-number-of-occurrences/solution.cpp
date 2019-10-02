class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, unsigned int> am;
        std::set<unsigned int> as;
        for ( int i: arr )
        {
            auto itr = am.find(i);
            if ( itr != am.end() )
            {
                itr->second++;
            }
            else
            {
                am[i] = 1;
            }
        }
        unsigned int index = 0;
        for (auto itr: am )
        {
            std::cout << "Inserting " << itr.first << " " << itr.second << std::endl;
            as.insert(itr.second);
            index++;
        }
        return (as.size() == index);
    }
};
