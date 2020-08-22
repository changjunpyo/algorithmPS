func sumFourDivisors(nums []int) int {
    ans :=0
    for _, val := range nums{
        tmp_ans := val+1
        count :=2
        if val <6{
            continue
        }
        for i:=2; count <=4 && i*i<=val;i++{
            if val %i ==0{
                if i*i == val{
                    count+=1
                } else{
                    count+=2
                }
                tmp_ans += (i + val/i)
            }
        }
        if count == 4{
            ans += tmp_ans
        }
    }
    return ans
}
