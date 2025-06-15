import (
	"fmt"

	"github.com/emirpasic/gods/utils"
	pq "github.com/emirpasic/gods/queues/priorityqueue"
)


type ElePair struct {
    Ele int
    Count int
}
// "-" descending order for min-heap
// Normal ascending order for max-heap
func pairComparator(i, j interface{}) int {
    countI := i.(ElePair).Count
    countJ := j.(ElePair).Count
    return utils.IntComparator(countI, countJ) 
}

func topKFrequent(nums []int, k int) []int {
    if len(nums) == k {
        return nums
    }
    m := make(map[int]int)
    for _, n := range nums {
        if v, exists := m[n]; exists {
            m[n] = v + 1
        } else {
            m[n] = 1
        }
    }

    mh := pq.NewWith(pairComparator)
    for ele, v := range m {
        mh.Enqueue(ElePair {Ele: ele, Count: v})
        if mh.Size() > k {
            mh.Dequeue()
        }
    }
    var vRet []int
    for !mh.Empty() {
		vEle, _ := mh.Dequeue()
		vRet = append(vRet, vEle.(ElePair).Ele)
	}
    return vRet
}
