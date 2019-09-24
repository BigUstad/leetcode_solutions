class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        //std::unordered_set<int> ns;
        vector<bool> ns(10000, false);
        for ( auto i: A )
        {
            if ( ns[i] == true )
                return i;
            else
                ns[i] = true;
        }
        /*for ( auto i: A )
        {
            if ( ns.find(i) != ns.end() )
                return i;
            else
                ns.insert(i);
        }*/
        return INT_MIN;
    }
};
