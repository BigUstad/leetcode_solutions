class Solution {
public:
    int numJewelsInStones(string J, string S)
    {
        std::locale loc;
        vector<char> v(53, 0);
        for ( char c: J )
        {
            if ( std::isupper(c, loc) )
                v[c - 'A' + 26]++;
            else
                v[c - 'a']++;
        }
        int count = 0;
        for ( char c: S )
        {
            if ( std::isupper(c, loc) && v[c-'A'+26] > 0 ) 
                count++;
            else if (std::islower(c, loc) && v[c-'a'] > 0)
                count++;
        }
        return count;
    }
    /*int numJewelsInStones(string J, string S) {
        set<char> js;
        for ( char c: J)
        {
            auto itr = js.find(c);
            if ( itr != js.end() )
            {
                
            }
            else
            {
                js.insert(c);
            }
        }
        int sc=0;//count
        for ( char c: S )
        {
            if ( js.find(c) != js.end() )
                sc++;
        }
        js.clear();
        return sc;
    }*/
};
