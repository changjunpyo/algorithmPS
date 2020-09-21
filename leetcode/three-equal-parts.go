func threeEqualParts(A []int) []int {
    one_position := make([]int, 0)
    for i:=0; i<len(A); i++{
        if A[i] == 1{
            one_position = append(one_position, i)
        }
    }
    
    if len(one_position) %3 != 0{
        return []int{-1,-1}
    } else if len(one_position) == 0{
        return []int{0, len(A)-1}
    }
    a, b, c := one_position[0], one_position[len(one_position)/3 ] , one_position[len(one_position)/3 *2]
     
    for i:=0; i<len(A)-c; i++{
        if A[a+i] != A[b+i] || A[a+i] != A[c+i]{
            return []int{-1,-1}
        }
    }
    return []int{a + len(A)-c -1, b+ len(A)-c}
}