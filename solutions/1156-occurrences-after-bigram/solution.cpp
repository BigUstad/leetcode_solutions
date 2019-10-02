class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> lRet;
        //std::unordered_map<string, vector<string>> tm;
        string word(first + string(" ") + second);
        std::cout << word << std::endl;
        size_t pos = 0;
        while ( (pos = text.find(word, pos)) != std::string::npos )
        {
            if ( pos != 0 && text[pos - 1] != ' ')
            {
                pos += word.length();
                continue;
            }
            pos += word.length();
            // Skip space.
            if ( pos >= text.length() )
                break;
            size_t nextPos = text.find(" ", pos + 1);
            string lWrd(text.substr(pos+1, (nextPos - pos - 1)));
            std::cout << lWrd << std::endl;
            lRet.push_back(lWrd);
        }
        
        return lRet;
    }
};
