class Solution {
public:
    string defangIPaddr(string address) {
        stringstream sstr;
        for ( int i=0; i < address.length(); ++i )
        {
            if ( address[i] != '.' )
                sstr << address[i];
            else
                sstr << "[.]";
        }
        return sstr.str();
    }
};
