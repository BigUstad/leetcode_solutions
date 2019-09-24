class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<char> vc(26,0);
        for ( char c: chars )
        {
            vc[c-'a']++;
        }
        int succWrd = 0;
        int succWrdCnt = 0;
        
        for ( string& word : words )
        {
            vector<char> copyvc(vc);
            bool fail = false;
            for( char c: word )
            {
                if ( --copyvc[c-'a'] < 0 )
                {
                    fail = true;
                    break;
                }
            }
            if ( !fail )
            {
                succWrd++;
                succWrdCnt += word.length();
            }
        }
        return succWrdCnt;
    }
};
