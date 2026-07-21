type RandomizedSet struct {
    randlist []int
    randmap map[int]int
}


func Constructor() RandomizedSet {
    return RandomizedSet {
        randlist: make([]int, 0, 50000),
        randmap: make(map[int]int, 50000),
    }
}


func (this *RandomizedSet) Insert(val int) bool {
    // Already exists
    if _, ok := this.randmap[val]; ok {
        return false
    }
    // New insert
    this.randlist = append(this.randlist, val)
    this.randmap[val] = len(this.randlist) - 1
    return true
}

func (this *RandomizedSet) Remove(val int) bool {
    targetIdx, ok := this.randmap[val]
    if !ok { return false }
    // Do the swap, I guess
    n := len(this.randlist)
    last := this.randlist[n - 1]
    // Update the map & list
    this.randlist[targetIdx] = last
    this.randmap[last] = targetIdx
    // Remove operation
    this.randlist = this.randlist[:n-1]
    delete(this.randmap, val)
    return true
}


func (this *RandomizedSet) GetRandom() int {
    ri := rand.N(len(this.randlist))
    return this.randlist[ri]
}


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
