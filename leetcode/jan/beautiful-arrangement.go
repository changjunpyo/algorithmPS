func recursiveCount(count, num int , flag []bool) int{
    if (count != 0  && (num % count != 0 && count % num != 0 )) {
        return 0
    } 
    if (count == len(flag)-1 ){
        return 1
    } 
    total := 0
    for i:=1; i<len(flag); i++{
        if (flag[i]){
            continue
        }
        flag[i] = true
        total += recursiveCount(count+1, i, flag)
        flag[i] = false
    }
    return total
}


func countArrangement(n int) int {
    flag := make([]bool, n+1)
    return recursiveCount(0,1,flag)
    
}