import "sort"


func solution(citations []int) int {
    sort.Ints(citations)
    ans := 0
    idx := 0
    for i:=len(citations)-1; i>=0; i--{
        idx++
        if idx <= citations[i]{
            ans = idx
        }
    }
    return ans
}