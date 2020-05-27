import "sort"
func solution(n int, lost []int, reserve []int) int {
    ans := n- len(lost)
    sort.Ints(lost)
    sort.Ints(reserve)
    for i,j:=0,0; i<len(lost) && j<len(reserve);{
        if reserve[j]-1<= lost[i] && lost[i]<=reserve[j]+1 {
            if i+1 < len(lost)&& reserve[j]== lost[i+1]{
                i++
                continue
            }else if j+1 <len(reserve)  && reserve[j+1] == lost[i]{
                j++
                continue
            }
            i++
            j++
            ans++
        } else if reserve[j]-1 > lost[i]{
            i++;
        } else if lost[i] > reserve[j]+1{
            j++
        }
    }
    return ans
}