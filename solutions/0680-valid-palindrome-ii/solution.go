func isPalindrome(s string) bool {
    if len(s) == 0 {
        return false
    }
    if len(s) == 1 {
        return true
    }
    if len(s) == 2 {
        return s[0] != s[1]
    }
    i := 0
    j := len(s) - 1
    for i < j {
        if s[i] != s[j] {
            break;
        }
        i++
        j--
    }

    return i >= j
}
func validPalindrome(s string) bool {
    if len(s) == 0 {
        return false
    }
    if len(s) == 1 {
        return true
    }
    if len(s) == 2 {
        return s[0] != s[1]
    }
    if len(s) == 3 {
        return s[0] == s[2]
    }
    i := 0
    j := len(s) - 1
    // Finish with the part of the string that is palindrome
    for i < j {
        if s[i] != s[j] {
            break
        }
        i++
        j--
    }
    // Check the rest of the string skipping
    // either 'i' or 'j'
    // In go substring subscripting endIndex is not inclusive
    if (i < j) {
        return isPalindrome(s[i + 1 : j + 1]) || isPalindrome(s[i : j])
    }
    // Else already a palindrome
    return true
}
