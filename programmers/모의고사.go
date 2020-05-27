func solution(answers []int) []int {
    st1 := []int{1,2,3,4,5,1,2,3,4,5}
    st2 := []int{2,1,2,3,2,4,2,5}
    st3 := []int{3,3,1,1,2,2,4,4,5,5}
    ans := make([]int,3)
    for i:=0; i<len(answers); i++{
        if answers[i] == st1[i%len(st1)]{
            ans[0]++
        }
        if answers[i] == st2[i%len(st2)]{
            ans[1]++
        }
        if answers[i] == st3[i%len(st3)]{
            ans[2]++
        }
    }
    max :=-1
    ret := make([]int,0)
    for i:=0; i<3; i++{
        if max < ans[i]{
            max = ans[i]
            ret = []int{i+1}
        }else if max == ans[i]{
            ret = append(ret, i+1)
        }
    }
   
    return ret
}