func arrayStringsAreEqual(word1 []string, word2 []string) bool {
    str1 := ""
    str2 := ""
    for _, v := range word1{
        str1 += v
    }
    for _, v := range word2{
        str2 += v
    }
    return str1 == str2
}