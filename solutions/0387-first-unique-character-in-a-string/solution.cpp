class Solution {
public:
    int firstUniqChar(string s) {
        std::map<char,int> cm;
        std::set<char, std::less<char>> cs;
        for ( size_t i=0; i < s.length(); ++i )
        {
            char c = s.at(i);
            auto cmItr = cm.find(c);
            if ( cmItr != cm.end() )
            {
                
                cmItr->second++;
            }
            else
            {
                cm[c] = 1;
            }
        }
        
        size_t leastIndex = -1;
        for ( auto itr = cm.begin(); itr != cm.end(); ++itr)
        {
            if ( itr->second == 1 )
            {
                std::cout << " Single " << itr->first << std::endl;
                cs.insert(itr->first);                
            }
        }

        for ( auto itr = cs.begin(); itr != cs.end(); ++itr )
        {
            size_t pos = s.find(*itr);
            if ( pos == std::string::npos )
                continue;
            if ( leastIndex == -1 )
                leastIndex = pos;
            else if ( pos < leastIndex )
            {
                leastIndex = pos;
            }
        }
        return leastIndex;
    }
};
