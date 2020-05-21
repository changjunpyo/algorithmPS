import ("sort"
        "strconv")

func solution(numbers []int) string {
    strings := make([]string, len(numbers))
    
    for i:=0; i<len(numbers); i++{
        strings[i] = strconv.Itoa(numbers[i])
    }
    sort.Slice(strings, func(i,j int)bool{
        return strings[i]+strings[j] > strings[j]+ strings[i]
    })
    ans := ""
    for i:=0 ; i<len(strings); i++{
        ans +=strings[i]
    }
    if strings[0] == "0"{
        return "0"
    }
    return ans
}
