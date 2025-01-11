func isPowerOfThree(n int) bool {
    if n < 1 {
        return false
    }
    if n == 1 {
        return true
    }
    r := n % 3
    q := n / 3
    if r > 0 {
        return false
    }
    return isPowerOfThree(q)

}
