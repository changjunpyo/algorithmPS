func lengthOfLongestSubstring(s string) int {
    if (len(s) == 0){
        return 0
    }
    m := make(map[byte]int)
    left, right := 0, 0
    ans := 0
    for right < len(s){
        if (m[s[right]] >= 1 ){
            m[s[left]]--
            left++
        } else{
            m[s[right]]++
            right++
            if (ans < right-left){
                ans = right-left
            }
        }
    }
    return ans
    
    
    
}