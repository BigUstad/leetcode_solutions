func maximumSubarraySum(nums []int, k int) int64 {
    var maxSum int64 = 0
    var currentSum int64 = 0
    
    // Track element frequencies in the current window
    counts := make(map[int]int)
    start := 0
    
    for end := 0; end < len(nums); end++ {
        // Add the rightmost element to the window
        endNum := nums[end]
        currentSum += int64(endNum)
        counts[endNum]++
        
        // If a duplicate is introduced, shrink from the left until resolved
        for counts[endNum] > 1 {
            startNum := nums[start]
            currentSum -= int64(startNum)
            counts[startNum]--
            if counts[startNum] == 0 {
                delete(counts, startNum)
            }
            start++
        }
        
        // If the window size exceeds k, shrink from the left by one
        if end - start + 1 > k {
            startNum := nums[start]
            currentSum -= int64(startNum)
            counts[startNum]--
            if counts[startNum] == 0 {
                delete(counts, startNum)
            }
            start++
        }
        
        // If the window is exactly size k (and guaranteed distinct), update max
        if end - start + 1 == k {
            if currentSum > maxSum {
                maxSum = currentSum
            }
        }
    }
    
    return maxSum
}

