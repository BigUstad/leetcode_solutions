import (
	pq "github.com/emirpasic/gods/queues/priorityqueue"
)

// latest on top
func pqIntervalComparator(a, b interface{}) int {
    sa := a.([]int)
    sb := b.([]int)
	return cmp.Or(
		cmp.Compare(sa[1], sb[1]),
		cmp.Compare(sa[0], sb[0]),
	)
}

func minIntervalComparator(a, b []int) int {
	return cmp.Or(
		cmp.Compare(a[0], b[0]),
		cmp.Compare(a[1], b[1]),
	)
}


func minMeetingRooms(intervals [][]int) int {
	l := len(intervals)
	if l <= 1 { return l }
	var roomPQ *pq.Queue
    roomPQ = pq.NewWith(pqIntervalComparator)
	slices.SortFunc(intervals, minIntervalComparator)
	for _, v := range intervals {
        // Pop the top to "empty" the room
        tEle, ok := roomPQ.Peek()
        if ok {
            t := tEle.([]int)
            // cur start time is at or later than top's end time
            if v[0] >= t[1] {
                roomPQ.Dequeue()
            }
        }
        // Push it to place somewhere in the queue to "use" the room
        roomPQ.Enqueue(v)
	}
    // The ones that couldn't be popped tell us how many extra rooms we need
	return roomPQ.Size()
}
