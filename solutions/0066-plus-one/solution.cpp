class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if ( digits.size() == 0 )
            return digits;
        int size = digits.size() - 1;
        digits[size] = digits[size] + 1;
        if ( digits[size] >= 10 )
        {
            int carryover = 0;
            for ( int i = size; (i >= 0);
                 --i)
            {
                int digit = digits[i];
                if ( carryover > 0 )
                {
                    digits[i] += carryover;
                    digit = digits[i];
                }
                digits[i] = digits[i] % 10;
                carryover = digit / 10;
                if ( carryover == 0 )
                    break;
            }
            if ( carryover > 0 )
            {
                digits.insert(digits.begin(), carryover);
            }
        }
        return digits;
    }
};
