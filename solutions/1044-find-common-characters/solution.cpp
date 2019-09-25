class Solution {
public:
    /*vector<string> commonChars(vector<string>& A) {
        vector<char> cv(26, 0);
        vector<string> lRet;
        lRet.reserve(A.size());
        int index = 0;
        for ( string& i: A )
        {
            for ( char c: i )
            {
                if (index == 0 )
                    cv[c-'a']++;
                else if ( index > 0  && cv[c-'a'] > 0 )
                    cv[c-'a']++;
                else if ( index > 0 && cv[c-'a'] < (index - 1) )
                    cv[c-'a'] = 0;
            }
            index++;
        }
        for(char i=0; i < cv.size(); ++i)
        {
            if ( cv[i] >= A.size() )
            {
                char c(i+'a');
                string s("");
                s.append(1,c);
                int count = cv[i]/A.size();
                while ( count-- )
                    lRet.push_back(s);
            }
        }
        return lRet;
    }*/
    vector<string> commonChars(vector<string>& A)
    {
        vector<string> lRet;
        vector<vector<char>> vm(A.size(), vector<char>(26,0));
        int index = 0;
        for ( auto i:A )
        {
            for ( char c:i )
            {
                vm.at(index).at(c-'a') += 1;
            }
            index++;
        }
        for(char i=0; i < 26; ++i)
        {
            bool inAll = true;
            size_t count = 0;
            for ( int j=0; j < vm.size(); ++j)
            {
                int smallcount = 0;
                if (vm[j].at(i) < 1)
                {
                    inAll = false;
                    break;                    
                }
                else
                {
                    //std::cout << "Found " << (char)(i + 'a') << " " 
                        //<< (int)(vm[j].at(i))<< std::endl;
                    if ( (count != 0 && count > vm[j].at(i)) || (count == 0) )
                        count = (int)(vm[j].at(i));
                    
                }
            }
            if ( inAll )
            {
                //std::cout << " For " << (char)(i+'a') << " count: " << count << std::endl;   
                //count = count / A.size();
                while ( count-- )
                {
                    string s("");
                    s.append(1,i+'a');
                    lRet.push_back(s);
                }
            }
        }
        return lRet;
    }
};
