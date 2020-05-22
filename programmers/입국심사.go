func binarySearch(s, e int64, n int, times []int) int64{
    p := len(times)
    for ; s < e ; {
        var m ,t int64
        m ,t = (s+e)/2 ,0
        for i:=0; i< p; i++{
            t += m/int64(times[i]);
        }
        
        if t >= int64(n){
            e = m    
        }else{
            s = m+1
        }
    }
    return s
}
func solution(n int, times []int) int64 {
    
    return binarySearch(0,int64(n)*int64(1000000000),n,times)
}
