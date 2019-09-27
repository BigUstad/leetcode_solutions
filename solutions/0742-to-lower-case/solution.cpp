class Solution {
public:
    string toLowerCase(string str) {
        stringstream ss;
        for ( char c: str )
        {
            if ( (int)c < 90 && (int)c >= 65 )
            {
                char diff = (c - 'A');
                char newChar = (char)(diff + 'a');
                ss << newChar;                
            }
            else
            {
                ss << c;
            }
        }
        return ss.str();
    }
};
