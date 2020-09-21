func lengthOfLIS(nums []int) int {
    dp := make([]int, len(nums))
    if len(nums) == 0{
        return 0
    }
    dp[0] = 1
    ans := 1
    for i:=1; i<len(nums); i++{
        dp[i] = 1
        for j:=i-1; j>=0; j--{
            if nums[i] <= nums[j]{
                continue
            } 
            if dp[j]+ 1 > dp[i]{
                dp[i] = dp[j]+1
            }
        }
        if ans < dp[i]{
            ans = dp[i]
        }
    }
    return ans
}