func checkInclusion(s1 string, s2 string) bool {
    s1Count := make([]int, 26)
    s2Count := make([]int, 26)
    for i:=0; i<len(s1); i++{
        s1Count[int(s1[i]-'a')]++
    }
    
    for i:=0; i<len(s2); i++{
        s2Count[int(s2[i] -'a')]++
        
        
        if i >= len(s1){
            s2Count[int(s2[i-len(s1)]-'a')]--
        }
        for j:=0; j<26; j++{
            if s1Count[j] != s2Count[j]{
                break
            }
            if j==25 {
                return true
            }
        }
    }
    return false
}