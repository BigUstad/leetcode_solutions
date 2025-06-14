func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    m := make(map[rune]int)
    for _, c := range s {
        v, exists := m[c]
        if exists {
            m[c] = v + 1
        } else {
            m[c] = 1
        }
    }
    for _, c := range t {
        v, exists := m[c]
        if !exists {
            return false
        }
        m[c] = v - 1
        if m[c] == 0 {
            delete(m, c)
        }
    }
    return len(m) == 0
}
