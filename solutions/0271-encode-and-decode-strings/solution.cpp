class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        if (!strs.size()) {
            std::string empty_strs = trademark_char_str + trademark_char_str;
            return empty_strs;
        }
        if (strs.size() == 1) {
            return trademark_char_str + copyright_char_str + strs[0] + copyright_char_str + trademark_char_str;
        }
        std::string l_ret;
        l_ret.append(trademark_char_str);
        for (auto& s: strs) {
            l_ret.append(copyright_char_str);
            l_ret.append(s);
            l_ret.append(copyright_char_str);
        }
        l_ret.append(trademark_char_str);
        return l_ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        std::vector<std::string> v;
        std::size_t pos = 0;
        std::string empty_strs = trademark_char_str + trademark_char_str;
        std::string blank_strs = trademark_char_str + copyright_char_str +
            copyright_char_str + trademark_char_str;

        // Check for an empty list
        if (s == empty_strs) {
            return v;
        }
        if (s == blank_strs) {
            return {""};
        }
        // Compile list
        for(size_t i = 0; i < s.length(); ) {
            std::string cur_trademark_char(s.substr(i, trademark_char_str.length()));

            if(cur_trademark_char == trademark_char_str) {
                i += trademark_char_str.length();
                continue;
            }
            // Find the word between copyright_char_str(s)
            std::size_t word_start_pos = (i + copyright_char_str.length());
            std::size_t word_end_pos = s.find(copyright_char_str, word_start_pos);
            // std::string decoded_word(s.substr((i + copyright_char_str.length()),
            //         (word_end_pos - word_start_pos)));
            v.push_back(s.substr(
                        (i + copyright_char_str.length()),
                        (word_end_pos - word_start_pos))
                        );
            i = word_end_pos + copyright_char_str.length();
        }
        return v;
    }
private:
    // From wiki: https://en.wikipedia.org/wiki/List_of_Unicode_characters
    const std::string copyright_char_str = "\u00A9"; // ©. The word delimiter.
    const std::string trademark_char_str =  "\u00AE"; // ®. The indicator for start and end of list.
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
