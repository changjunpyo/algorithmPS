func carPooling(trips [][]int, capacity int) bool {
    a:= make([]int, 1001)
    
    for i:=0; i<len(trips); i++{
        a[trips[i][1]] += trips[i][0]
        a[trips[i][2]] -= trips[i][0]
    }
    count :=0
    for i:=0; i<=1000; i++{
        count += a[i];
        if count > capacity{
            return false
        }
    }
    return true
}