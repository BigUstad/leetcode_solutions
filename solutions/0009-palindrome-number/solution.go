/*
 * Given an integer x, return true if x is a  palindrome, and false otherwise.
 */
func isPalindrome(x int) bool {
    const MaxUint = ^uint(0) 
    const MinUint = 0 
    const MaxInt = int(MaxUint >> 1) 
    const MinInt = -MaxInt - 1
    if x == 0 {
        return true
    }
    if x < 0 {
        return false
    }
    if x > 0 && x < 10 {
        return true
    }
    if x < 0 {
        x = int(math.Abs(float64(x)))
    }
    origX := x
    y := 10
    r := 0
    rev := 0
    q := 0
    for x != 0 {
        q = x / y
        r = x % y
        rev = rev * 10 + r
        x = q
    }
    return rev == origX
}
