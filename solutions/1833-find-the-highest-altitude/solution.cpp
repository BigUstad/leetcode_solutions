class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // Calculate prefix sums
        for (int index = 1; index < gain.size(); ++index) {
            gain[index] = gain[index - 1] + gain[index];
        }
        std::sort(gain.begin(), gain.end());
        return (gain[gain.size() - 1] < 0)? 0 : gain[gain.size() - 1];
    }
};
