func isAnagram(s string, t string) bool {
    ans := make([]int,26)
    if len(s) != len(t){
        return false;
    }
    for i:=0; i<len(s); i++{
        ans[int(s[i]-'a')]++;
        ans[int(t[i]-'a')]--;
    }
    for i:=0; i<26; i++{
        if ans[i] != 0 {return false}
    }
    return true
}
