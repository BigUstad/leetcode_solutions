class Solution {
public:
    bool isAnagram(string s, string t) {
        int totalXor = 0;
        vector<char> cv(26,0);
        vector<char> cv2(26,0);
        bool lRet = true;
        for ( char c: s )
        {
            totalXor ^= c;
            cv[c-'a']++;
        }
        for ( char c: t )
        {
            totalXor ^= c;
            cv2[c-'a']++;
        }
        if ( totalXor != 0 )
            return false;// No need to perform further check. Increase performance.
        for ( int i = 0; i < 26; i++ )
        {
            if (cv2[i] != cv[i] )
                return false;
        }
        return true;
    }
};
