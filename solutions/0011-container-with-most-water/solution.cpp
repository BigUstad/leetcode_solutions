class Solution {
public:
    int maxArea(vector<int>& height) {
        int start_index = 0, end_index =(height.size() - 1);
        int prev_area_max = 0, cur_area = 0, cur_area_max = -1;
        while (start_index < end_index) {
            cur_area = (std::min(height[start_index], height[end_index]) *
                        (end_index - start_index));
            prev_area_max = cur_area_max;
            cur_area_max = std::max(cur_area, prev_area_max);
            /* std::cout << "{" << height[start_index] << "," << start_index << "}" <<
                      "| {" << height[end_index] << "," << end_index << "} = " << cur_area << std::endl; */
            // Move the index based on what is smaller
            if (height[start_index] < height[end_index]) {
                ++start_index;
            } else {
                --end_index;
            }
        }
        // std::cout << "cur_area_max = " << cur_area_max << std::endl;
        return cur_area_max;
    }
};

