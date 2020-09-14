class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [[0,0],[0,0]]
        for idx,val in enumerate(nums):
            x, y= max(dp[1][-1], dp[1][-2]) ,max(val+dp[0][-1],dp[1][-2] + val )
            dp[0].append(x)
            dp[1].append(y)
            
        return max(dp[0][-1], dp[1][-1])