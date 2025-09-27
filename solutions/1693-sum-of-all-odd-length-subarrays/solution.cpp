class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int total_prefix_sum = 0, last = (arr.size() - 1);
        std::vector<int> nums_prefix_sum;
        for (auto& a: arr) {
            total_prefix_sum += a;
        }
        // nums_prefix_sum.push_back(arr[0]);
        // std::cout << "nums_prefix_sum: " << arr[0];
        for (int index = 1; index < arr.size(); ++index) {
            // std::cout << "  " << nums_prefix_sum[index - 1] + arr[index];
            // nums_prefix_sum.push_back((nums_prefix_sum[index - 1] + arr[index]));
            arr[index] = arr[index - 1] + arr[index];
        }
        // std::cout << std::endl;
        for (int i = 2; i <= last; i += 2) {
            int index = i;
            while (index <= last) {
                /* if (index > i) {
                    std::cout << (index - i - 1) << ". " << nums_prefix_sum[index] << ", " << nums_prefix_sum[index - i] << " = ";
                    std::cout << (nums_prefix_sum[index] - nums_prefix_sum[index - i - 1]) << std::endl;
                } */
                /* total_prefix_sum += (index > i) ?
                    (nums_prefix_sum[index] - nums_prefix_sum[index - i - 1]) :
                        nums_prefix_sum[index]; */
                total_prefix_sum += (index > i) ?
                    (arr[index] - arr[index - i - 1]) :
                        arr[index];
                ++index;
            }
        }
        return total_prefix_sum;
    }
};
