func containsDuplicate(nums []int) bool {
    m := make(map[int]bool)
    for _, n := range nums {
        _, exists := m[n]
        if exists {
            return true
        }
        m[n] = false
    }
    return false
}
