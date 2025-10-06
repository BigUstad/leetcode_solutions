class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if ( !s.length() )
            return 0;
        size_t runner = 1;
        size_t follower  = 0;
        size_t tracker = 0;
        int foundLth = 1;
        std::unordered_set<char> chrSet;
        // O(n2). Not good
        chrSet.insert(s[follower]);
        while ( follower < (s.length() - 1) &&
                runner < s.length() )
        {
            if ( chrSet.find(s[runner]) == chrSet.end() )
            {
                // Unique char
                //std::cout << " Inserting: " << s[runner] << std::endl;
                chrSet.insert(s[runner]);
                ++runner;                
                foundLth = std::max( foundLth, (int)chrSet.size() );
            }
            else
            {
                // This follower index doesn't cut it, so let's do the next one..
                //std::cout << " Length: " << foundLth << " " << chrSet.size() << std::endl;
                //std::cout << " Clear & start again." << std::endl;
                chrSet.clear();
                follower++;
                chrSet.insert(s[follower]);
                runner = follower + 1;
            }
        }
        chrSet.clear();
        return foundLth;
    }
};

