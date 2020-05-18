func findAnagrams(s string, p string) []int {
    ans := make([]int, 0)
    pCount := make([]int, 26)
    sCount := make([]int, 26)
    for i:=0; i<len(p); i++{
        pCount[int(p[i]-'a')]++
    }
    
    for i:=0; i<len(s); i++{
        sCount[int(s[i] -'a')]++
        
        
        if i >= len(p){
            sCount[int(s[i-len(p)]-'a')]--
        }
        for j:=0; j<26; j++{
            if pCount[j] != sCount[j]{
                break
            }
            if j==25 {
                ans = append(ans,i-len(p)+1)
            }
        }
    }
    return ans
    
}
