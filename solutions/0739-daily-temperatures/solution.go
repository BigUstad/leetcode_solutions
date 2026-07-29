import lls "github.com/emirpasic/gods/stacks/linkedliststack"

func dailyTemperatures(temperatures []int) []int {
	n := len(temperatures)
	if n == 0 {
		return []int{}
	}
	if n == 1 {
		return []int{temperatures[0]}
	}
	if n == 2 {
		if temperatures[0] > temperatures[1] {
			return []int{temperatures[0]}
		}
		return []int{temperatures[1]}
	}
	warmer := make([]int, n)
	stack := lls.New()
	for i, t := range temperatures {
		var sTop int
        sEle, ok := stack.Peek()
        if ok { sTop = sEle.(int) }
		for ok && t > temperatures[sTop] {
			// Next warmer day is x days away
			warmer[sTop] = (i - sTop)
			stack.Pop()
			sEle, ok = stack.Peek()
            if ok { sTop = sEle.(int) }
		}
		stack.Push(i)
	}
    return warmer
}

