func searchForRow(matrix [][]int, target int) (int, bool) {
    // If 1 row just return
    // fmt.Print("rows: ")
    // fmt.Println(len(matrix))
    if len(matrix) == 1 {
        return 0, false
    }
    // low in row = 0
    // high in row at (m*n) -1
    n := len(matrix[0]) - 1
    l := 0
    h := len(matrix) - 1
    if target < matrix[0][0] || target > matrix[len(matrix) - 1][n] {
        return -1, false
    }
    for l <= h {
        m := l + ((h - l) / 2);
        // fmt.Println(m)
        // fmt.Println((target >= matrix[m][0] && target <= matrix[m][n]))
        if target >= matrix[m][0] && target <= matrix[m][n] {
            // fmt.Print(m)
            // fmt.Print(",")
            return m, (target == matrix[m][0] || target == matrix[m][n])
        }
        if target > matrix[m][0] {
            l = m + 1
        } else {
            h = m - 1
        }
        // fmt.Print(l)
        // fmt.Print(",,")
        // fmt.Println(h)
    }
    return -1, false

}
func searchMatrix(matrix [][]int, target int) bool {
    if len(matrix) <= 0 {
        return false
    }
    // First find the right row. Via binary search. 
    // Then find the element within that row.
    n := len(matrix[0]) - 1
    r, foundAlready := searchForRow(matrix, target)
    if foundAlready { return true }
    if r < 0 { return false }
    if r == 0 && n == 0 {
        return matrix[0][0] == target
    }
    // Now just proper binary search
    l := 0
    h := len(matrix[0]) - 1
    for l <= h {
        m := l + ((h - l)/2)
        if target == matrix[r][m] {
            // fmt.Println(m)
            return true
        }
        if target > matrix[r][m] {
            l = m + 1
        } else {
            h = m - 1
        }
    }

    return false
}
