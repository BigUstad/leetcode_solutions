import "github.com/emirpasic/gods/stacks/arraystack"

const (
    open_param = '('
    close_param = ')'
    open_sq = '['
    close_sq = ']'
    open_fl = '{'
    close_fl = '}'
)

func isValid(s string) bool {
    if (len(s) == 0) {
        return true
    }
    if (len(s) % 2) != 0 {
        return false
    }
    stck := arraystack.New()
    for _, c := range s {
        is_open :=  (c == open_param ||
                     c == open_sq ||
                     c == open_fl)
        if is_open {
            stck.Push(c)
            continue
        }
        if stck.Empty() {
            return false
        }
        top, _ := stck.Pop()
        is_mismatched := (top == open_param && c != close_param ||
                          top == open_sq && c != close_sq ||
                          top == open_fl && c != close_fl)
        if is_mismatched {
            return false
        }
    }
    return stck.Empty()
}
