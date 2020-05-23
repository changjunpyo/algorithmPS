func intervalIntersection(A [][]int, B [][]int) [][]int {


    ans := make([][]int, 0)
    a_idx:=0
    b_idx:=0
    // 6 case -> but this is not good...
    //  A , B 의[idx][0] 중 최대값, [idx][1] 중 최소값을 이용하면 더 깔끔한 코드가 나올 듯

    for ;a_idx<len(A) && b_idx<len(B) ;{
        if A[a_idx][1] < B[b_idx][0] {
            a_idx++
        }else if A[a_idx][0] > B[b_idx][1] {
            b_idx++
        }else if A[a_idx][0]<= B[b_idx][0] && B[b_idx][1]<=A[a_idx][1]{
            ans = append(ans, B[b_idx])
            b_idx++
        }else if B[b_idx][0]<= A[a_idx][0] && A[a_idx][1]<=B[b_idx][1]{
            ans = append(ans, A[a_idx])
            a_idx++
        }else if A[a_idx][0] <= B[b_idx][0] && A[a_idx][1] <= B[b_idx][1]{
            par := []int{B[b_idx][0],A[a_idx][1]}
            ans = append(ans, par)
            a_idx++
        }else if B[b_idx][0] <= A[a_idx][0] && B[b_idx][1] <= A[a_idx][1]{
            par := []int{A[a_idx][0],B[b_idx][1]}
            ans = append(ans, par)
            b_idx++
        }
    }
    return ans
}