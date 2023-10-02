class Solution {
public:
    string decodeMessage(string& key, string& message) {
        stringstream decodedStream;
        createKeyMap(key);
        for (const char& c: message ) {
            char index = keyMapFindValue(c);
            if ( c == ' ') {
                decodedStream << c;
                continue;
            }
            if ( index == -1 ) {
                std::cout << "Index: " << index << " for " << c << std::endl;
                return "";
            }
            char cIns ('a' + index);
            decodedStream << cIns;
        }
        return decodedStream.str();
    }
private:
    std::vector<char> keyMap;
    void createKeyMap(string& key) {
        keyMap.reserve(28);
        std::unordered_set<char> cSet;
        for ( unsigned char i = 0; i < 26; i++) {
            keyMap.push_back('A');
        }
        unsigned char i = 0;
        for (char& c: key ) {
            if ( c == ' ') {
                continue;
            }
            // Insert only if not already inserted
            auto inspair = cSet.insert(c);
            if ( inspair.second == true ) {
                keyMap[i] = c;
                i++;
            }
        }
    }
    char keyMapFindValue(char cToFind) {
        char i = 0;
        for ( const char& c: keyMap ) {
            if ( c == cToFind ) {
                return i;
            }
            i++;
        }
        return -1;
    }

};
