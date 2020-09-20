func maxProfit(prices []int) int {
    
    minimum := math.MaxInt32
    ans := 0
    for _, val := range prices{
        if ans < val- minimum{
            ans = val - minimum
        } else if minimum > val{
            minimum = val
        }
    }
    return ans
}