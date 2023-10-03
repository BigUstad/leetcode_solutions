class Solution {
public:
    bool checkIfPangram(string& sentence) {
        std::vector<bool> keyMap;
        unsigned char i = 0;
        for (  ; i < 26; ++i) {
            keyMap.push_back(false);
        }
        for ( char& c: sentence ) {
            if ( c == ' ') {
                continue;
            }
            keyMap[c - 'a'] = true;
        }
        for ( i = 0; i < 26; ++i ) {
            if ( keyMap[i] == false ) {
                return false;
            }
        }
        return true;
    }
};
