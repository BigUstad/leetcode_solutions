 type Interval struct {
    start int
    end   int
}

// Ascending
func minIntervalComparator(a, b Interval) int {
	return cmp.Or(
		cmp.Compare(a.start, b.start),
		cmp.Compare(a.end, b.end),
		)
}

func canAttendMeetings(intervals [][]int) bool {
	l := len(intervals)
	if l <= 1 { return true }
    var theIntervals []Interval
    for _, i := range intervals {
        theIntervals = append(theIntervals, Interval{
            start: i[0],
            end: i[1],
        })
    }
	slices.SortFunc(theIntervals, minIntervalComparator)
	// fmt.Println(intervals)
	for i, v := range theIntervals {
		// No more comparisons left
		if i == l - 1 {
			break
		}
		// Check overlap
		if v.end > theIntervals[i+1].start {
			return false
		}
	}
    return true
}
