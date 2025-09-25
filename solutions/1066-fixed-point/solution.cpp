class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int last = (arr.size() - 1);
        int low = 0, high = last;
        int index = -1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            // std::cout << "mid: " << mid << std::endl;
            if (arr[mid] == mid) {
                // Search for a smaller index continues
                index = mid;
                high = mid - 1;
            } else if (arr[mid] < mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return index;
    }
};
