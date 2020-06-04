
func Abs(x int) int {
        if x < 0 {
                return -x
        }
        return x
}


func twoCitySchedCost(costs [][]int) int {
    sum :=0
    // time: O(N^2) space : O(N)
    /*
    isA := make([]bool, len(costs))
    sum := 0
    N := len(costs)/2
    countA := 0
    countB := 0
    for i:=0; i<len(costs); i++{
        if costs[i][0] > costs[i][1]{
            if countB >= N{
                mn := 10000
                idx := 0
                isA[i] = false
                sum += costs[i][1]
                for j:=0; j<=i; j++{
                    if !isA[j]{
                        if mn > Abs(costs[j][0]-costs[j][1]){
                            idx = j
                            mn = Abs(costs[j][0]-costs[j][1])
                        }
                    }
                }
                isA[idx] = true
                sum += mn
                countA++
            } else {
                countB++
                sum += costs[i][1]
                isA[i] = false
            }
        } else{
            if countA >= N{
                mn := 10000
                idx := 0
                isA[i] = true
                sum += costs[i][0]
                for j:=0; j<=i; j++{
                    if isA[j]{
                        if mn > Abs(costs[j][0]-costs[j][1]){
                            idx = j
                            mn = Abs(costs[j][0]-costs[j][1])
                        }
                    }
                }
                isA[idx] = false
                sum += mn
                countB++
            } else {
                countA++
                sum += costs[i][0]
                isA[i] = true
            }
        }
    }
    */
    // time : O(NlogN) space : O(1)
    sort.Slice(costs, func(x, y int) bool{
        return costs[x][0]-costs[x][1] < costs[y][0]-costs[y][1]
    })
    
    for i:=0; i<len(costs)/2; i++{
        sum += costs[i][0] + costs[i+len(costs)/2][1]
    }
    return sum
}