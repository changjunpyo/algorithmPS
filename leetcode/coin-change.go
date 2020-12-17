func min(a, b int) int{
    if a < b {
        return a
    }
    return b
}

func coinChange(coins []int, amount int) int {
    dp := make([][]int, len(coins))

    for i:=0; i<len(coins); i++{
        dp[i] = make([]int, amount+1)
        for j:=0; j<amount+1; j++{
            dp[i][j] = -1
        }
    }
    for i:=0; i<len(coins); i++{
        for j:=0; j<amount+1; j++{
            if i != 0 {
                dp[i][j] = dp[i-1][j]
            }
            if coins[i] == j{
                dp[i][j] = 1
            } else if j- coins[i] < 0 {
                continue
            } else {
                if (dp[i][j-coins[i]] == -1){
                    continue
                }
    
                if dp[i][j] == -1{
                    dp[i][j] = dp[i][j-coins[i]] +1
                } else{
                    dp[i][j] = min(dp[i][j],dp[i][j-coins[i]] +1)
                }
            }
        }
    }
    if amount == 0 {
        return 0
    }
    return dp[len(coins)-1][amount] 
}