class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<std::string> lRet;
        if ( n <= 0 ) return lRet;
        do
        {
            bool both = ( (n%3 == 0) && (n%5 == 0) );
            bool either = ( ( n % 3 == 0) || ( n % 5 == 0) );
            
            if ( both )
                lRet.insert(lRet.begin(), "FizzBuzz");
            else if (either)
            {
                lRet.insert(lRet.begin(), (( n % 3 == 0)?"Fizz":"Buzz"));
            }
            else
            {
                lRet.insert(lRet.begin(), std::to_string(n));
            }
        }
        while ( --n );
        return lRet;
    }
};
