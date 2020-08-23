func singleNumber(nums []int) int {
    m := make(map[int]int)
    
    for _, val := range nums{
        v, exist := m[val]
        if !exist{
            m[val] = 1
        } else{
            if v == 1{
                m[val] +=1
            } else {
                delete(m, val)
            }
        }
        
    }
    for key, _ := range m{
        return key
    }
    return -1
}
