func groupAnagrams(strs []string) [][]string {
    am := make(map[string][]int)
    for i, s := range strs {
        r := []rune(s)
        sort.Slice(r, func(i, j int) bool {
            return r[i] < r[j]
        })
        mv, exists := am[string(r)]
        if exists {
            am[string(r)] = append(mv, i)
        } else {
            am[string(r)] = []int{i}
        }
    }

    // fmt.Print("len of map: ")
    // fmt.Println(len(am))
    rstrs := make([][]string, len(am))
    ri := 0
    for _, v := range am {
        // fmt.Print("len of inside arr: ")
        // fmt.Println(len(v))
        rstrs[ri] = make([]string, len(v))
        for i, iv := range v {
            rstrs[ri][i] = strs[iv]
        }
        ri++
    }
    return rstrs
}
