func maxArea(height []int) int {
    start, end := 0, (len(height) - 1)
    prevAreaMax, curArea, curAreaMax := 0, 0, 0

    // Lets move the indices after area calculations
    // Two pointers approach. Earlier the better as bottom needs to be maximized
    for start < end {
        curArea = min(height[start], height[end]) * (end - start)
        prevAreaMax = curAreaMax
        curAreaMax = max(curArea, prevAreaMax)
        if height[start] < height[end] {
            start++
        } else {
            end--
        }
    }
    return curAreaMax
}
