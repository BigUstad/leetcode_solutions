func longestPalindrome(s string) string {
    // This solution is the one closest to neetcode video
    n := len(s)
    if n == 0 {
        return ""
    }

    start, maxLen := 0, 1

    expand := func(left, right int) {
        for left >= 0 && right < n && s[left] == s[right] {
            currLen := right - left + 1

            if currLen > maxLen {
                maxLen = currLen
                start = left
            }

            left--
            right++
        }
    }

    for i := 0; i < n; i++ {
        // Odd-length palindrome
        expand(i, i)

        // Even-length palindrome
        expand(i, i+1)
    }

    return s[start : start+maxLen]
}

