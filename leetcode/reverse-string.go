func reverseString(s []byte)  {
    l := len(s)
    for i:=0; i<len(s)/2; i++{
        s[i] ,s[l-i-1] = s[l-i-1], s[i]
    }
    
}