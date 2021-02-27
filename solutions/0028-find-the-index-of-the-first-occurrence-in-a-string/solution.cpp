class Solution {
public:
    int strStr(string haystack, string needle) {
        string s1 = haystack; string s2 = needle;
        if (s1.length() == 0 && s2.length() == 0)
            return 0;
        if (s1.length() == 0)
            return -1;
        if (s2.length() == 0)
            return 0;
        // return for strlen 0
        if (s2.length() > s1.length())
            return -1;
        int s1index = 0;
        int s2index = 0;
        int curIndex = 0;
        while (curIndex < s1.length())
        {
            if (s1.at(curIndex) == s2.at(0))
            {
                int s1startIndex = curIndex;
                s1index = s1startIndex;
                s2index = 0;
                while(s2index < s2.length() &&
                      s1index < s1.length() &&
                        s1.at(s1index) == s2.at(s2index))
                {
                    s1index++;
                    s2index++;
                }
                cout << s2index << " " << s2.length() << endl;
                if (s2index == s2.length())//a match
                    return s1startIndex;
                // else continue looking till end.
                //*(s1+1) = '\0'
                //return s1
            }
            cout << (s1index > curIndex) << " " << s1index << " " << curIndex << endl;
            curIndex++;
        }
        
        return -1;        
    }
};
