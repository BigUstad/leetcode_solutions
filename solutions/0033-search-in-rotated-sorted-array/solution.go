func findMinIndex(nums []int) int {
    low := 0
    high := len(nums) - 1
    last := len(nums) - 1
    for low <= high {
        mid := low + ((high - low)/2)
        // Edge conditions
        if mid == 0 {
            if nums[mid] < nums[mid + 1] {
                return 0
            }
            return mid + 1
        }
        if mid == last {
            if nums[mid] < nums[mid - 1] {
                return last 
            }
            return last - 1
        }
        // Find pivot & minIndex
        if nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1] {
            return mid
        }
        if nums[mid] > nums[last] {
            low = mid + 1
        } else {
            high = mid - 1
        }
    }
    // Shouldn't happen
    return -1
}

func search(nums []int, target int) int {
    // Edge conditions
    if len(nums) == 0 { return -1 }
    if len(nums) == 1 {
        if target == nums[0] {
            return 0
        }
        return -1
    }
    if len(nums) == 2 {
        if target == nums[0] {
            return 0
        } else if target == nums[1] {
            return 1
        }
        return -1
    }
    minIndex := findMinIndex(nums)
    // fmt.Print("minIndex: ")
    // fmt.Println(minIndex)
    last := len(nums) - 1
    index := -1
    found := false
    // Find the right sub-array
    // Perform binary search there
    if minIndex == 0 {
        index, found = slices.BinarySearch(nums, target)
    } else if target <= nums[last] {
        index, found = slices.BinarySearch(nums[minIndex:], target)
        index += minIndex
    } else {
        index, found = slices.BinarySearch(nums[0:minIndex], target)
    }
    if !found { return -1 }
    return index
}
