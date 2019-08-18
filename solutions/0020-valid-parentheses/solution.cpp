class Solution {
public:
    bool isValid(string s) {
        size_t sLth = s.length();
        // std::cout << " Length " << sLth << std::endl;
        if ( sLth == 0 )
            return true;
        if ( sLth == 1)
            return false;
        std::string validChars("[]{}()");
        bool lRet = true;
        for( int i =0 ; (i < sLth && lRet); ++i )
        {
            char curS = s.at(i);

            if (curS == '(' || curS == '[' || curS == '{' )
            {
                // std::cout << " Pushing at " << i << " " << curS << std::endl;
                cStack.push(s.at(i));
            }
            else if ( (curS == ')' || curS == ']' ||curS == '}')
                      && !cStack.empty() )
            {
                char stckTop = cStack.top();
                // std::cout << " Popping at " << i << " " << stckTop << " for " << curS << std::endl;
                switch(stckTop)
                {
                    case '(':
                        {
                            if( curS != ')' )
                            {
                                lRet = false;
                            }
                            break;
                        }
                    case '[':
                        {
                            if( curS != ']' )
                            {
                                lRet = false;
                            }
                            break;
                        }
                    case '{':
                        {
                            if( curS != '}' )
                            {
                                lRet = false;
                            }
                            break;
                        }
                    default:
                        lRet = false;
                }
                cStack.pop();

            }
            else if ( (curS == ')' || curS == ']' ||curS == '}')
                      && cStack.empty() )
            {
                // std::cout << " AT " << i << " " << curS << " without corresponding one in stack." << std::endl;
                lRet = false;
            }
        }
        if ( !cStack.empty() )
            lRet = false;
        return lRet;
        
    }
private:
    std::stack<char> cStack;
};
