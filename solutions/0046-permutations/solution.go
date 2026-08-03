func backtrack(nums []int, curIdxs []int, allResults *[][]int) {
	// fmt.Println(curIdxs)
	if len(curIdxs) == len(nums) {
		var res []int
		for i := 0; i < len(curIdxs); i++ {
			res = append(res, nums[curIdxs[i]])
		}
        // fmt.Println(res)
		*allResults = append(*allResults, res)
	}
	for i := 0; i < len(nums); i++ {
		found := false
		for _, c := range curIdxs {
			if i == c {
				found = true
				break
			}
		}
		if !found && len(curIdxs) < len(nums) {
			curIdxs = append(curIdxs, i)
			backtrack(nums, curIdxs, allResults)
			curIdxs = curIdxs[:len(curIdxs)-1]
		}
	}
}

func permute(nums []int) [][]int {
	if len(nums) == 0 { return [][]int{nums} }
	if len(nums) == 1 { return [][]int{{nums[0]}} }
	var allResults [][]int
	for i := 0 ; i < len(nums); i++ {
		backtrack(nums, []int{i}, &allResults)
	}
	return allResults
}

