func findKthPositive(arr []int, k int) int {
    for i:=0; i< len(arr); i++{
        if (arr[i] - i-1 >= k){
            return i+k
        }
    }
    return len(arr)+ k
}