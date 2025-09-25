class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        std::vector<int> missing;
        int start, end;
        int last = arr[(arr.size() - 1)];
        last += k;
        // std::cout << "last: " << last << std::endl;
        for (int i = 1; i <= last; ++i) {
            start = 0;
            end = (arr.size() - 1);
            bool found = false;
            while (start <= end) {
                int mid = start + ((end - start) / 2);
                if (arr[mid] == i) {
                    found = true;
                    break;
                }
                if (arr[mid] < i) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            // std::cout << "found " << i << "? " << ((found)?"Yes":"No") << std::endl;
            if (!found) {
                // std::cout << i << std::endl;
                missing.push_back(i);
            }
        }
        // std::cout << missing.size() << std::endl;
        return missing[k - 1];
    }
};
