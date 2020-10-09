class Solution {
public:
    bool isPalindrome(int x) {
            int origx = x;
            if(x<0)
            {
                return false;
            }
            if(x<10)
            {
                return true;
            }
            if(x>2147483647)
            {
                return false;
            }
            int y = 10;
            int z = 1;
            int w = 0;
            int p = 1;
            while (x > 0)
            {
                p = x/y;
                z = x % y;
                if (w > (INT_MAX/10))
                    return false;
                w = w * 10 + z; 
                x = p;
            }
            return w == origx;
    }
};
