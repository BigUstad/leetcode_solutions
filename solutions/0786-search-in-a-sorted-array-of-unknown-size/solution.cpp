/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int low = 0, high = 10000, last = 9999;
        // First find the high, I guess. Then find the target.
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (reader.get(mid) < INT_MAX && reader.get(mid + 1) == INT_MAX) {
                high = mid;
                break;
            }
            if (reader.get(mid) < INT_MAX) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // std::cout << "new_high: " << high << std::endl;
        low = 0;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            // std::cout << "mid: " << mid << " ele: " << reader.get(mid) << std::endl;
            if (reader.get(mid) == target) {
                return mid;
            }
            if (reader.get(mid) < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
