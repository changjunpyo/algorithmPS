// A_1 = 1
// A_2 = 2
// A_n+2 = A_n+1 + A_n
// This problem is basically fibonacci 
func climbStairs(n int) int {
    if n == 1{
        return 1
    } 
    x, before_x := 1, 1
    
    for i:= 1; i<n; i++ {
        x , before_x = x + before_x , x 
    }
    
    return x
}
