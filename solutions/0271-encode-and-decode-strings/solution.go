type Codec struct {
    
}
const r_trademark rune = '\u00AE'
const r_copyright rune = '\u00A9'
const empty_arr_encoded string = string(r_trademark) + string(r_trademark)

// Encodes a list of strings to a single string.
func (codec *Codec) Encode(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    if len(strs) == 1 {
        return strings.Join([]string{string(r_trademark), strs[0], string(r_trademark)}, "")
    }
    return strings.Join(strs, string(r_copyright))
}

// Decodes a single string to a list of strings.
func (codec *Codec) Decode(strs string) []string {
    if len(strs) == 0 {
        return []string{}
    }
    // Special case for array with one empty string
    if strs == empty_arr_encoded {
        return []string{""}
    }
    // Special case for single array item
    if strs[0:len(string(r_trademark))] == string(r_trademark) {
        strs = strings.Trim(strs, string(r_trademark))
        return []string{strs}
    }
    // Lose the leading & trailing r_trademark
    ret := strings.Split(strs, string(r_copyright))
    return ret
}

// Your Codec object will be instantiated and called as such:
// var codec Codec
// codec.Decode(codec.Encode(strs));
