func isPalindrome(s string) bool {
    j := len(s)
    if j == 0 || j == 1 {
        return true
    }
    s = strings.ToLower(s)
    i := 0
    j = len(s) - 1
    for i <= j {
        // Skip comparing non alphanumeric letters
        if !unicode.IsLetter(rune(s[i])) && !unicode.IsNumber(rune(s[i])) {
            i++
            continue
        }
        if !unicode.IsLetter(rune(s[j])) && !unicode.IsNumber(rune(s[j])) {
            j--
            continue
        }
        // Comparing only alphanumeric
        if (s[i] != s[j]) {
            break
        }
        i++
        j--
    }
    return (i >= j)
}
