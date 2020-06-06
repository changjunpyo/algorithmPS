func reconstructQueue(people [][]int) [][]int {
    sort.Slice(people, func(i,j int) bool{
        if people[i][0] == people[j][0]{
            return people[i][1]< people[j][1]
        }
        return people[i][0] > people[j][0]
    })
    ans := make([][]int, 0, len(people))
    for i:=0; i<len(people); i++{
        fmt.Println(people[i][0],people[i][1])
        idx :=0
        count :=0
        for ; idx<len(ans); idx++{
            if count == people[i][1]{
                break
            }
            count++
        }
        
        ans = append(ans[:idx+1], ans[idx:]...)
        ans[idx] = people[i]
    }
    return ans
}