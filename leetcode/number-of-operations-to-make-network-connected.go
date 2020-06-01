
func find(a int , uni []int) int{
    if uni[a] == a{
        return a
    }
    uni[a] = find(uni[a] , uni)
    return uni[a]
}

func union(a,b int, uni,cnt []int){
    x := find(a, uni)
    y := find(b, uni)
    if x != y{
        if cnt[x] < cnt[y]{
            uni[x] = y
        } else{
            uni[y] = x
            if cnt[x] == cnt[y] {
                cnt[x]++
            }
        }
    }
}
func makeConnected(n int, connections [][]int) int {
    num := len(connections)
    if n-1 > num{
        return -1
    }
    uni := make([]int, n)
    cnt := make([]int, n)
    for i:=0; i<n; i++{
        uni[i] = i
        cnt[i] = 0
    }
    for i:=0; i<len(connections); i++{
        union(connections[i][0], connections[i][1], uni,cnt)
    }
    m := make(map[int]int)
    for i:=0; i<n; i++{
        m[find(i,uni)]+=1
    }
    count :=0
    for _,v := range m{
        if v !=0{
            count++
        }
    }
    
    return count-1
}