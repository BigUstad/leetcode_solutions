class Solution {
public:
    int numberOfSteps (int num) {
        int trynum = num;
        int numSteps = 0;
        while ( trynum > 0 ) {
            if (trynum%2 == 0) {
                trynum = trynum / 2;
            } else {
                trynum -= 1;
            }
            numSteps++;
        } 
        return numSteps;
    }
};
