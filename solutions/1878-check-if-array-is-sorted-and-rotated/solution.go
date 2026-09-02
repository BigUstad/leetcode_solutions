func check(nums []int) bool {
    n := len(nums)
    drops := 0

    for i := 0; i < n; i++ {
        next := (i + 1) % n

        if nums[i] > nums[next] {
            drops++
            if drops > 1 {
                return false
            }
        }
    }

    return true
}
