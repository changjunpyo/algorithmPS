func removeCoveredIntervals(intervals [][]int) int {
    ans:=len(intervals)
    sort.Slice(intervals, func(a,b int) bool{
        if intervals[a][0] == intervals[b][0] {
            return intervals[a][1] > intervals[b][1]
        }
        return intervals[a][0] <intervals[b][0]
    } )
    before := make([]int,2)
    for _, val := range intervals{
        if val[1] <= before[1]{
            ans--
            continue
        }
        before = val
    }
    return ans
}