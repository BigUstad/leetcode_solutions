class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 )
            return false;
        if ( x == 0 )
            return true;
        std::string lStrx = std::to_string(x);
        bool lOdd = false;
        if ( lStrx.length() == 1 )
        {
            return true;
        }
        if ( lStrx.length() == 2 )
        {
            return (lStrx.at(0) == lStrx.at(1));
        }
        if ( lStrx.length()%2 != 0)
        {
            lOdd = true;
        }
        int lMid;
        if ( lOdd )
        {
            lMid = ceil( lStrx.length()/2 );
        }
        else
        {
            lMid = lStrx.length()/2;
        }
        for (int i=(lMid -1), j=( lOdd?(lMid+1):lMid ) ; ( i >= 0 && j < lStrx.length() );
              --i, ++j)
        {
            if ( lStrx.at(i) != lStrx.at(j))
                return false;
        }
        return true;
    }
};
