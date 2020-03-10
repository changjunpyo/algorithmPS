func subarraySum(nums []int, k int) int {
    ret , sum := 0, 0
    m := make(map[int]int, len(nums))
    m[0] = 1
    for i := range nums {
        sum += nums[i]
        ret += m[sum-k]
        m[sum] +=1
    }
    return ret
    
}