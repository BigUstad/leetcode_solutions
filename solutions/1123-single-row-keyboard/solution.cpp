class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unsigned int timeTaken = 0;
        unsigned short prevIdx;
        unsigned short index = 0;
        constructMap(keyboard);
        for ( const auto& c: word ) {
            unsigned short& s = cm[c];
            if ( index > 0 ) {
                timeTaken += std::abs(s - prevIdx);
            } else {
                timeTaken = s;
            }
            prevIdx = s;
            index++;
        }
        return timeTaken;
    }
private:
    void constructMap(const string& keyboard) {
        unsigned short index = 0;
        for ( const auto& c: keyboard ) {
            cm[c] = index++;
        }
    }
    std::unordered_map<unsigned char, unsigned short> cm;
};
