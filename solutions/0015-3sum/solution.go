
func threeSum(nums []int) [][]int {
	// 1. Binary Search REQUIRES the slice to be sorted first
	slices.Sort(nums)
	var result [][]int
    confirmUnique := make(map[string]bool)

	// Fix the loop order: i -> j -> binary search window
	for i := 0; i < len(nums)-2; i++ {
		// Skip duplicate values for 'i' to avoid duplicate triplets
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		for j := i + 1; j < len(nums)-1; j++ {
			// Skip duplicate values for 'j'
			if j > j+1 && nums[j] == nums[j-1] {
				continue
			}

			// Math is perfect: 0 - A - B = C
			complement := 0 - nums[i] - nums[j]

			// Search window MUST be to the right of 'j' (from j+1 to the end of the slice)
			subIdx, found := slices.BinarySearch(nums[j+1:], complement)

			if found {
				// Map the sub-index back to the main slice index
				k := subIdx + (j + 1)
                cKey := strings.Join(
                    []string {strconv.Itoa(nums[i]), strconv.Itoa(nums[j]), strconv.Itoa(nums[k])},
                    ",",
                    )
                if !confirmUnique[cKey] {
				    result = append(result, []int{nums[i], nums[j], nums[k]})
                    confirmUnique[cKey] = true
                }
			}
		}
	}
	return result
}

