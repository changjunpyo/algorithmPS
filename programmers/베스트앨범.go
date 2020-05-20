import "sort"

type Pair struct{
    val, idx int
}
type GenresObject struct{
    total int
    pairList []Pair
}
func solution(genres []string, plays []int) []int {
    ans := make([]int, 0)
    m := make(map[string]GenresObject)
    for i:=0; i<len(plays); i++{
        m[genres[i]] = GenresObject{m[genres[i]].total+plays[i], append(m[genres[i]].pairList, Pair{plays[i],i})}
    }
    list := make([]GenresObject, len(m))
    idx :=0
    for _, v := range m{
        list[idx] = v
        idx++
    } 
    sort.Slice(list, func(i,j int) bool{
        return list[i].total > list[j].total
    })
    
    for i:=0; i<len(list); i++{
        max := 0
        idx1,idx2 := 0, 0
        for j:=0; j < len(list[i].pairList); j++{
            if max <list[i].pairList[j].val{
                max = list[i].pairList[j].val
                idx1 = j
            }
        }
        ans = append(ans,list[i].pairList[idx1].idx)
        if len(list[i].pairList) == 1 {
            continue
        }
        max =0
        for j:=0; j<len(list[i].pairList); j++{
            if idx1 == j {continue}
            if max <list[i].pairList[j].val{
                max = list[i].pairList[j].val
                idx2 = j
            }
        }
        ans = append(ans,list[i].pairList[idx2].idx)
    }
    
    return ans
}