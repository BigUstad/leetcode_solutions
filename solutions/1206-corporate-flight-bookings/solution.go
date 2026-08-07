func corpFlightBookings(bookings [][]int, n int) []int {
    diffArr := make([]int, n+1)
    for _, b := range bookings {
        diffArr[b[0]-1] += b[2]
        diffArr[b[1]] -= b[2]
    }
    // fmt.Println(diffArr)
    res := make([]int, n+1)
    prev := 0
    for i, d := range diffArr {
        if i == 0 {
            res[i] = 0
            if d > 0 {
                res[i] = d
            }
        } else {
            res[i] = prev + d
        }
        prev = res[i]
    }
    // fmt.Println(res)
    return res[0:n]
}
