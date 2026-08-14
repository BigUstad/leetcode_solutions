func countMaxOrSubsets(nums []int) int {
    n := len(nums)
    if n == 0 { return n }
    // countmaps := make(map[int]int)
    var backtrack func(int, int)
    maxOR := 0
    count := 0
    for _, x := range nums {
        maxOR |= x
    }
    // fmt.Println(maxOR)
    backtrack = func(start int, currentOR int) {
        // current subset's currentOR, let's add it to countmaps
        // fmt.Print(nums[start:])
        // fmt.Print(" -> ")
        // fmt.Println(currentOR)
        if currentOR == maxOR { count++ }
        // Explore all the subsets of nums
        for i := start; i < n; i++ {
            // Calculate the running OR value
            backtrack(i+1, currentOR|nums[i])
        }
    }
    backtrack(0, 0)
    /*maxOR := math.MinInt
    for k, _ := range countmaps {
        maxOR = max(maxOR, k)
    }*/
    return count

}
