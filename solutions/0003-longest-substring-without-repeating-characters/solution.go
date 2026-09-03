func lengthOfLongestSubstring(s string) int {
    charSet := make(map[byte]bool)
    l, res := 0, 0

    for r := 0; r < len(s); r++ {
        for charSet[s[r]] {
            delete(charSet, s[l])
            l++
        }
        charSet[s[r]] = true
        if r - l + 1 > res {
            res = r - l + 1
        }
    }
    return res
}
