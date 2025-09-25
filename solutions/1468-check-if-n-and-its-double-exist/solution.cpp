class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int last = (arr.size() - 1);
        int low = 0, high = last;
        std::sort(arr.begin(), arr.end());
        int i = 0;
        for (auto& a: arr) {
            int prod = (2 * a);
            // std::cout << "a: " << a << ", 2a: " << prod << std::endl;
            low = 0; high = last;
            while (low <= high) {
                int mid = low + ((high - low) / 2);
                // std::cout << "mid: " << mid << ", ele: " << arr[mid] << std::endl;
                // Second condition is if element is 0.
                if (arr[mid] == prod && mid != i) {
                    return true;
                }
                if (arr[mid] < prod) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ++i;
        }
        return false;
    }
};
