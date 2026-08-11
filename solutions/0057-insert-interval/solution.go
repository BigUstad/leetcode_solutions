// func notOverlapping(intervals [][]int, newInterval []int, position int) bool {
//     if len(intervals) <= 2 {
//         if position == 0 {
//             return newInterval[1] < intervals[0][0]
//         } else if position == 1 {
//             return newInterval[0] > intervals[0][1]
//         } else {
//             return newInterval[0] > intervals[1][1]
//         }
//     }
//     if newInterval[0] > intervals[position-1][1] && newInterval[1] < intervals[position+1][0] {
//         return true
//     }
//     return false
// }

func insert(intervals [][]int, newInterval []int) [][]int {
    if len(intervals) <= 0 {
        return [][]int{newInterval}
    }
    // idx, found := slices.BinarySearchFunc(intervals, newInterval, func(a, b []int) int {
    //     return cmp.Compare(a[0], b[0])
    // })
    // if !found && notOverlapping(intervals, newInterval, idx) {
    //     return slices.Insert(intervals, idx, newInterval)
    // }
    var res [][]int
    l := len(intervals)
    idx := 0
    for idx < l && intervals[idx][1] < newInterval[0] {
        res = append(res, intervals[idx])
        idx++
    }
    // Modulate the new interval to be inserted
    for idx < l && newInterval[1] >= intervals[idx][0] {
        newInterval[0] = int(math.Min(float64(intervals[idx][0]), float64(newInterval[0])))
        newInterval[1] = int(math.Max(float64(intervals[idx][1]), float64(newInterval[1])))
        idx++
    }
    res = append(res, newInterval)
    // The rest? 
    res = append(res, intervals[idx:]...)
    return res
}
